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
    Buyer* buyer = system.getLoggedInBuyer();

    if (buyer == nullptr) {
        throw std::runtime_error("Error: Only logged-in buyers can cancel orders!");
    }

    buyer->cancel(purchaseId);

    std::cout << "Success: Order #" << purchaseId << " has been canceled. Amount refunded.\n";
}