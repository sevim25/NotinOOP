#include "CheckoutCommand.h"
#include "System/NotinOOP.h"
#include "Users/Buyer.h"
#include <iostream>
#include <stdexcept>

CheckoutCommand::CheckoutCommand(NotinOOP& system) : system(system) {}

void CheckoutCommand::execute()
{
    Buyer* buyer = system.getLoggedInBuyer();
    if (buyer == nullptr) {
        throw std::runtime_error("Error: Only logged-in buyers can checkout!");
    }
    buyer->checkout();
    std::cout << "Success: Checkout completed successfully.\n";
}