#pragma once
#include <string>
#include <vector>

enum class UserRole {
    BUYER,
    SELLER,
    ADMIN
};

class User {
private:
    int userId;
    std::string name;
    std::string email;
    std::string phone;
    UserRole role;

public:
    User(int id, const std::string& name, const std::string& email, 
         const std::string& phone, UserRole role);
    
    // Getters
    int getUserId() const { return userId; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    std::string getPhone() const { return phone; }
    UserRole getRole() const { return role; }

    // Setters
    void setName(const std::string& newName) { name = newName; }
    void setEmail(const std::string& newEmail) { email = newEmail; }
    void setPhone(const std::string& newPhone) { phone = newPhone; }
    void setRole(UserRole newRole) { role = newRole; }

    // Utility methods
    bool isAdmin() const { return role == UserRole::ADMIN; }
    bool isSeller() const { return role == UserRole::SELLER; }
    bool isBuyer() const { return role == UserRole::BUYER; }
}; 