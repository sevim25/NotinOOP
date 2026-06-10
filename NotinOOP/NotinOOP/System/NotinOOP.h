#pragma once
#include <vector>
#include <memory>
#include <string>

#include "Users/User.h"
#include "Entities/Fragrance.h"
#include "Entities/Purchase.h"
#include "Users/Admin.h"

#include <fstream>

class Admin;
class Buyer;
class Fragrance;

class NotinOOP
{
    std::vector<std::unique_ptr<User>> users;
    std::vector<std::unique_ptr<Fragrance>> fragrances;
    std::vector<Purchase> purchases;

    User* loggedUser;
    Admin* loggedAdmin;
    Buyer* loggedBuyer;

    void loadFragrances(std::ifstream& in, const std::string& firstToken);
    void loadUsers(std::ifstream& in, const std::string& role);
    void loadPurchases(std::ifstream& in, const std::string& firstToken);

public:
    NotinOOP();

    void registerBuyer(const std::string& username, const std::string& password);
    void login(const std::string& username, const std::string& password);
    void logout();

    User* getLoggedInUser() const;
    Admin* getLoggedInAdmin() const;
    Buyer* getLoggedInBuyer() const;

    void run();

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};