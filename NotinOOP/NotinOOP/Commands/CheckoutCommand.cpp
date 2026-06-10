#include "CheckoutCommand.h"
#include "System/NotinOOP.h"
#include "Users/Buyer.h"
#include <iostream>
#include <stdexcept>

CheckoutCommand::CheckoutCommand(NotinOOP& system) : system(system) {}

void CheckoutCommand::execute()
{
    try {
        Buyer* buyer = system.getLoggedInBuyer();
        if (buyer == nullptr) {
            std::cout << "Error: Only logged-in buyers can checkout!\n";
            return;
        }

        buyer->checkout();
        std::cout << "Success: Checkout completed successfully.\n";
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}