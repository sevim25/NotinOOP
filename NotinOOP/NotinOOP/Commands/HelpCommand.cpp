#include "HelpCommand.h"
#include "System/NotinOOP.h"
#include "Users/User.h"
#include <iostream>

HelpCommand::HelpCommand(NotinOOP& system) : system(system) {}

void HelpCommand::execute()
{
    User* user = system.getLoggedInUser();
    if (user == nullptr) {
        cout << "Available commands:\n";
        cout << "register <username> <password>\n";
        cout << "login <username> <password>\n";
        cout << "end\n";
        cout << "help\n";
        return;
    }

    if (user->getRole() == "ADMIN") {
        cout << "Available Admin commands:\n";
        cout << "logout\n";
        cout << "help\n";
        cout << "block-user <username>\n";
        cout << "create-fragrance <name> <brand> <price> <fragranceFamily>\n";
        cout << "add-quantity <fragrance-name> <quantity>\n";
        cout << "deliver <purchase-id>\n";
        cout << "remove-review <fragrance-id> <review-id>\n";
        cout << "end\n";
    }
    else {
        cout << "Available Buyer commands:\n";
        cout << "logout\n";
        cout << "help\n";
        cout << "add-to-balance <amount>\n";
        cout << "add-to-wishlist <fragrance-name>\n";
        cout << "remove-from-wishlist <fragrance-name>\n";
        cout << "add-to-cart <fragrance-name>\n";
        cout << "remove-from-cart <fragrance-name>\n";
        cout << "view-cart\n";
        cout << "view-bought\n";
        cout << "view-purchases\n";
        cout << "recommend\n";
        cout << "checkout\n";
        cout << "cancel <purchase-id>\n";
        cout << "make-review <fragrance-name> <rating> <comment>\n";
        cout << "end\n";
    }
}