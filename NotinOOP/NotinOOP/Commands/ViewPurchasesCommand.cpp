#include "ViewPurchasesCommand.h"
#include "System/NotinOOP.h"
#include "Users/Buyer.h"
#include <iostream>
#include <stdexcept>

ViewPurchasesCommand::ViewPurchasesCommand(NotinOOP& system) : system(system) {}

void ViewPurchasesCommand::execute()
{
    try {
        Buyer* buyer = system.getLoggedInBuyer();
        if (buyer == nullptr) {
            std::cout << "Error: Only logged-in buyers can view their purchase history!\n";
            return;
        }

        buyer->viewPurchases();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}