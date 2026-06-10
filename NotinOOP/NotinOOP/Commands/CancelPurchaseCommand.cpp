#include "CancelPurchaseCommand.h"
#include "System/NotinOOP.h"
#include "Users/Buyer.h"
#include <iostream>
#include <stdexcept>

CancelPurchaseCommand::CancelPurchaseCommand(NotinOOP& system, unsigned purchaseId)
    : system(system), purchaseId(purchaseId) {
}

void CancelPurchaseCommand::execute()
{
    try {
        Buyer* buyer = system.getLoggedInBuyer();
        if (buyer == nullptr) {
            std::cout << "Error: Only logged-in buyers can cancel purchases!\n";
            return;
        }

        buyer->cancel(purchaseId);
        std::cout << "Success: Purchase #" << purchaseId << " has been canceled.\n";
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}