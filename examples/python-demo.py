# Python Demo Code for Screenshots
import asyncio
import aiohttp
from dataclasses import dataclass
from typing import List, Optional, Dict, Any
from datetime import datetime
import json


@dataclass
class User:
    id: int
    name: str
    email: str
    avatar: Optional[str] = None
    created_at: datetime = datetime.now()


class UserService:
    def __init__(self, base_url: str = "https://api.example.com/users"):
        self.base_url = base_url
        self.session: Optional[aiohttp.ClientSession] = None

    async def __aenter__(self):
        self.session = aiohttp.ClientSession()
        return self

    async def __aexit__(self, exc_type, exc_val, exc_tb):
        if self.session:
            await self.session.close()

    async def get_users(self) -> List[User]:
        """Fetch all users from the API"""
        if not self.session:
            raise RuntimeError("UserService must be used as async context manager")
        
        try:
            async with self.session.get(self.base_url) as response:
                response.raise_for_status()
                data = await response.json()
                return [
                    User(
                        id=user_data["id"],
                        name=user_data["name"],
                        email=user_data["email"],
                        avatar=user_data.get("avatar")
                    )
                    for user_data in data
                ]
        except aiohttp.ClientError as e:
            print(f"Failed to fetch users: {e}")
            raise

    async def create_user(self, user_data: Dict[str, Any]) -> User:
        """Create a new user"""
        if not self.session:
            raise RuntimeError("UserService must be used as async context manager")
        
        try:
            async with self.session.post(self.base_url, json=user_data) as response:
                response.raise_for_status()
                data = await response.json()
                return User(
                    id=data["id"],
                    name=data["name"],
                    email=data["email"],
                    avatar=data.get("avatar")
                )
        except aiohttp.ClientError as e:
            print(f"Failed to create user: {e}")
            raise


async def main():
    """Main function to demonstrate usage"""
    async with UserService() as user_service:
        try:
            # Fetch users
            users = await user_service.get_users()
            print(f"Found {len(users)} users")
            
            # Create new user
            new_user_data = {
                "name": "John Doe",
                "email": "john.doe@example.com",
                "avatar": "https://example.com/avatars/john.jpg"
            }
            
            new_user = await user_service.create_user(new_user_data)
            print(f"Created user: {new_user.name} ({new_user.email})")
            
            # Display all users
            for user in users:
                print(f"User {user.id}: {user.name} - {user.email}")
                
        except Exception as e:
            print(f"Error: {e}")


if __name__ == "__main__":
    asyncio.run(main())
