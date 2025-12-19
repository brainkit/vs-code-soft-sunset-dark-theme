// Rust Demo Code for Theme Screenshots

use std::collections::HashMap;
use std::sync::{Arc, Mutex};
use tokio::sync::mpsc;

#[derive(Debug, Clone)]
pub struct User {
    pub id: u64,
    pub name: String,
    pub email: String,
    pub avatar: Option<String>,
    pub is_active: bool,
}

impl User {
    pub fn new(id: u64, name: &str, email: &str) -> Self {
        Self {
            id,
            name: name.to_string(),
            email: email.to_string(),
            avatar: None,
            is_active: true,
        }
    }

    pub fn with_avatar(mut self, avatar: &str) -> Self {
        self.avatar = Some(avatar.to_string());
        self
    }
}

#[derive(Debug)]
pub enum UserError {
    NotFound(u64),
    InvalidEmail(String),
    DatabaseError(String),
}

impl std::fmt::Display for UserError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            UserError::NotFound(id) => write!(f, "User not found: {}", id),
            UserError::InvalidEmail(email) => write!(f, "Invalid email: {}", email),
            UserError::DatabaseError(msg) => write!(f, "Database error: {}", msg),
        }
    }
}

pub trait UserRepository {
    async fn find_by_id(&self, id: u64) -> Result<Option<User>, UserError>;
    async fn save(&self, user: &User) -> Result<(), UserError>;
    async fn delete(&self, id: u64) -> Result<bool, UserError>;
}

pub struct InMemoryUserRepository {
    users: Arc<Mutex<HashMap<u64, User>>>,
}

impl InMemoryUserRepository {
    pub fn new() -> Self {
        Self {
            users: Arc::new(Mutex::new(HashMap::new())),
        }
    }
}

impl UserRepository for InMemoryUserRepository {
    async fn find_by_id(&self, id: u64) -> Result<Option<User>, UserError> {
        let users = self.users.lock().unwrap();
        Ok(users.get(&id).cloned())
    }

    async fn save(&self, user: &User) -> Result<(), UserError> {
        let mut users = self.users.lock().unwrap();
        users.insert(user.id, user.clone());
        Ok(())
    }

    async fn delete(&self, id: u64) -> Result<bool, UserError> {
        let mut users = self.users.lock().unwrap();
        Ok(users.remove(&id).is_some())
    }
}

async fn process_users(tx: mpsc::Sender<User>, users: Vec<User>) {
    for user in users {
        if user.is_active {
            let _ = tx.send(user).await;
        }
    }
}

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    let repo = InMemoryUserRepository::new();
    
    let user = User::new(1, "Alice", "alice@example.com")
        .with_avatar("https://example.com/avatar.png");
    
    repo.save(&user).await?;
    
    if let Some(found_user) = repo.find_by_id(1).await? {
        println!("Found user: {:?}", found_user);
    }

    let numbers: Vec<i32> = (1..=10).filter(|n| n % 2 == 0).collect();
    let sum: i32 = numbers.iter().sum();
    
    println!("Even numbers: {:?}, Sum: {}", numbers, sum);

    Ok(())
}
