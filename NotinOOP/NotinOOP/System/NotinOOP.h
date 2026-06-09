#pragma once
#include <vector>
#include <memory>
#include <string>

#include "Users/User.h"
#include "Entities/Fragrance.h"
#include "Entities/Purchase.h"

class NotinOOP
{
    std::vector<std::unique_ptr<User>> users;
    std::vector<std::unique_ptr<Fragrance>> fragrances;
    std::vector<Purchase> purchases;

    User* loggedUser;

public:
    NotinOOP();

    void registerBuyer(const std::string& username, const std::string& password);
    void login(const std::string& username, const std::string& password);
    void logout();

    User* getLoggedInUser() const;

    void run();
};