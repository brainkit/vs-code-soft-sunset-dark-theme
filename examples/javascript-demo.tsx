// TypeScript/JavaScript Demo Code for Screenshots
import { useState, useEffect } from 'react';
import axios from 'axios';

interface User {
  id: number;
  name: string;
  email: string;
  avatar?: string;
}

class UserService {
  private baseUrl: string = 'https://api.example.com/users';

  async getUsers(): Promise<User[]> {
    try {
      const response = await axios.get<User[]>(this.baseUrl);
      return response.data;
    } catch (error) {
      console.error('Failed to fetch users:', error);
      throw error;
    }
  }

  async createUser(userData: Omit<User, 'id'>): Promise<User> {
    const response = await axios.post<User>(this.baseUrl, userData);
    return response.data;
  }
}
/**
 * 
 * @param userId 
 * @returns UserProfile Component
 */
const UserProfile: React.FC<{ userId: number }> = ({ userId }) => {
  const [user, setUser] = useState<User | null>(null);
  const [loading, setLoading] = useState<boolean>(true);
  const [error, setError] = useState<string | null>(null);

  useEffect(() => {
    const userService = new UserService();
    
    const fetchUser = async () => {
      try {
        setLoading(true);
        const users = await userService.getUsers();
        const foundUser = users.find(u => u.id === userId);
        setUser(foundUser || null);
      } catch (err) {
        setError(err instanceof Error ? err.message : 'Unknown error');
      } finally {
        setLoading(false);
      }
    };

    fetchUser();
  }, [userId]);

  if (loading) return <div className="loading">Loading...</div>;
  if (error) return <div className="error">Error: {error}</div>;
  if (!user) return <div className="not-found">User not found</div>;

  return (
    <div className="user-profile">
      <img src={user.avatar || '/default-avatar.png'} alt={user.name} />
      <h2>{user.name}</h2>
      <p>{user.email}</p>
    </div>
  );
};

export default UserProfile;
