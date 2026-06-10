#include "HelpCommand.h"
#include "System/NotinOOP.h"
#include "Users/User.h"
#include <iostream>

HelpCommand::HelpCommand(NotinOOP& system) : system(system) {}

void HelpCommand::execute()
{
    User* user = system.getLoggedInUser();

    cout << '\n';

    if (user == nullptr) {
        std::cout << "Available commands:\n" << '\n'
            << "-> register <username> <password>\n"
            << "-> login <username> <password>\n"
            << "-> end\n"
            << "-> help\n";
        return;
    }

    if (user->asAdmin() != nullptr) {
        std::cout << "Available Admin commands:\n" << '\n'
            << "-> logout\n"
            << "-> help\n"
            << "-> block-user <username>\n"
            << "-> create-fragrance <name> <brand> <price> <fragranceFamily>\n"
            << "-> add-quantity <fragrance-name> <quantity>\n"
            << "-> deliver <purchase-id>\n"
            << "-> remove-review <fragrance-id> <review-id>\n"
            << "-> end\n";
    }
    else {
        std::cout << "Available Buyer commands:\n" << '\n'
            << "-> logout\n"
            << "-> help\n"
            << "-> add-to-balance <amount>\n"
            << "-> add-to-wishlist <fragrance-name>\n"
            << "-> remove-from-wishlist <fragrance-name>\n"
            << "-> add-to-cart <fragrance-name>\n"
            << "-> remove-from-cart <fragrance-name>\n"
            << "-> view-cart\n"
            << "-> view-bought\n"
            << "-> view-purchases\n"
            << "-> recommend\n"
            << "-> checkout\n"
            << "-> cancel <purchase-id>\n"
            << "-> make-review <fragrance-name> <rating> <comment>\n"
            << "-> end\n";
    }
}