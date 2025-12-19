// C Demo Code for Theme Screenshots

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 64
#define MAX_EMAIL_LENGTH 128

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    bool is_active;
} User;

typedef struct {
    User users[MAX_USERS];
    int count;
} UserRepository;

typedef enum {
    SUCCESS = 0,
    ERROR_NOT_FOUND = -1,
    ERROR_FULL = -2,
    ERROR_INVALID = -3
} ResultCode;

UserRepository* create_repository(void) {
    UserRepository* repo = (UserRepository*)malloc(sizeof(UserRepository));
    if (repo != NULL) {
        repo->count = 0;
        memset(repo->users, 0, sizeof(repo->users));
    }
    return repo;
}

void destroy_repository(UserRepository* repo) {
    if (repo != NULL) {
        free(repo);
    }
}

ResultCode add_user(UserRepository* repo, int id, const char* name, const char* email) {
    if (repo == NULL || name == NULL || email == NULL) {
        return ERROR_INVALID;
    }
    
    if (repo->count >= MAX_USERS) {
        return ERROR_FULL;
    }
    
    User* user = &repo->users[repo->count];
    user->id = id;
    strncpy(user->name, name, MAX_NAME_LENGTH - 1);
    strncpy(user->email, email, MAX_EMAIL_LENGTH - 1);
    user->is_active = true;
    
    repo->count++;
    return SUCCESS;
}

User* find_user_by_id(UserRepository* repo, int id) {
    if (repo == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < repo->count; i++) {
        if (repo->users[i].id == id) {
            return &repo->users[i];
        }
    }
    return NULL;
}

ResultCode delete_user(UserRepository* repo, int id) {
    if (repo == NULL) {
        return ERROR_INVALID;
    }
    
    for (int i = 0; i < repo->count; i++) {
        if (repo->users[i].id == id) {
            // Shift remaining users
            for (int j = i; j < repo->count - 1; j++) {
                repo->users[j] = repo->users[j + 1];
            }
            repo->count--;
            return SUCCESS;
        }
    }
    return ERROR_NOT_FOUND;
}

void print_user(const User* user) {
    if (user != NULL) {
        printf("User { id: %d, name: \"%s\", email: \"%s\", active: %s }\n",
               user->id, user->name, user->email,
               user->is_active ? "true" : "false");
    }
}

int calculate_sum(const int* numbers, size_t count) {
    int sum = 0;
    for (size_t i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum;
}

int main(void) {
    UserRepository* repo = create_repository();
    
    if (repo == NULL) {
        fprintf(stderr, "Failed to create repository\n");
        return EXIT_FAILURE;
    }
    
    add_user(repo, 1, "Alice", "alice@example.com");
    add_user(repo, 2, "Bob", "bob@example.com");
    add_user(repo, 3, "Charlie", "charlie@example.com");
    
    printf("All users:\n");
    for (int i = 0; i < repo->count; i++) {
        print_user(&repo->users[i]);
    }
    
    User* found = find_user_by_id(repo, 2);
    if (found != NULL) {
        printf("\nFound: ");
        print_user(found);
    }
    
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = calculate_sum(numbers, sizeof(numbers) / sizeof(numbers[0]));
    printf("\nSum of numbers: %d\n", sum);
    
    destroy_repository(repo);
    return EXIT_SUCCESS;
}
