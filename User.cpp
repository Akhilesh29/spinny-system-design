#include "include/User.h"

User::User(int id, const std::string& name, const std::string& email, const std::string& phone, UserRole role)
    : userId(id), name(name), email(email), phone(phone), role(role) {} 