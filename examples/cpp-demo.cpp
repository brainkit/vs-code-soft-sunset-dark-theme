// C++ Demo Code for Theme Screenshots

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <optional>
#include <unordered_map>
#include <algorithm>
#include <functional>

namespace app {

template<typename T>
class Result {
public:
    static Result<T> ok(T value) {
        return Result<T>(std::move(value), std::nullopt);
    }
    
    static Result<T> error(std::string message) {
        return Result<T>(std::nullopt, std::move(message));
    }
    
    bool is_ok() const { return value_.has_value(); }
    bool is_error() const { return error_.has_value(); }
    
    const T& value() const { return *value_; }
    const std::string& error() const { return *error_; }

private:
    Result(std::optional<T> value, std::optional<std::string> error)
        : value_(std::move(value)), error_(std::move(error)) {}
    
    std::optional<T> value_;
    std::optional<std::string> error_;
};

struct User {
    int id;
    std::string name;
    std::string email;
    std::optional<std::string> avatar;
    bool is_active = true;
    
    User(int id, std::string name, std::string email)
        : id(id), name(std::move(name)), email(std::move(email)) {}
    
    User& with_avatar(std::string url) {
        avatar = std::move(url);
        return *this;
    }
};

class IUserRepository {
public:
    virtual ~IUserRepository() = default;
    virtual Result<std::optional<User>> find_by_id(int id) = 0;
    virtual Result<void*> save(const User& user) = 0;
    virtual Result<bool> remove(int id) = 0;
};

class InMemoryUserRepository : public IUserRepository {
public:
    Result<std::optional<User>> find_by_id(int id) override {
        auto it = users_.find(id);
        if (it != users_.end()) {
            return Result<std::optional<User>>::ok(it->second);
        }
        return Result<std::optional<User>>::ok(std::nullopt);
    }
    
    Result<void*> save(const User& user) override {
        users_[user.id] = user;
        return Result<void*>::ok(nullptr);
    }
    
    Result<bool> remove(int id) override {
        auto erased = users_.erase(id);
        return Result<bool>::ok(erased > 0);
    }
    
    std::vector<User> get_active_users() const {
        std::vector<User> active;
        for (const auto& [id, user] : users_) {
            if (user.is_active) {
                active.push_back(user);
            }
        }
        return active;
    }

private:
    std::unordered_map<int, User> users_;
};

class UserService {
public:
    explicit UserService(std::shared_ptr<IUserRepository> repo)
        : repository_(std::move(repo)) {}
    
    Result<User> create_user(int id, const std::string& name, const std::string& email) {
        User user(id, name, email);
        auto result = repository_->save(user);
        if (result.is_error()) {
            return Result<User>::error(result.error());
        }
        return Result<User>::ok(std::move(user));
    }
    
    Result<std::optional<User>> get_user(int id) {
        return repository_->find_by_id(id);
    }

private:
    std::shared_ptr<IUserRepository> repository_;
};

} // namespace app

int main() {
    using namespace app;
    
    auto repo = std::make_shared<InMemoryUserRepository>();
    UserService service(repo);
    
    auto result = service.create_user(1, "Alice", "alice@example.com");
    if (result.is_ok()) {
        std::cout << "Created user: " << result.value().name << std::endl;
    }
    
    service.create_user(2, "Bob", "bob@example.com");
    service.create_user(3, "Charlie", "charlie@example.com");
    
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::vector<int> even_numbers;
    std::copy_if(numbers.begin(), numbers.end(), 
                 std::back_inserter(even_numbers),
                 [](int n) { return n % 2 == 0; });
    
    int sum = std::accumulate(even_numbers.begin(), even_numbers.end(), 0);
    
    std::cout << "Even numbers sum: " << sum << std::endl;
    
    auto active_users = repo->get_active_users();
    std::cout << "Active users: " << active_users.size() << std::endl;
    
    return 0;
}
