#include "DeliverCommand.h"
#include <iostream>   
#include <string>     
#include <stdexcept>  

#include "System/NotinOOP.h" 
#include "Users/User.h"
#include "Users/Admin.h"
#include "Users/Buyer.h"

DeliverCommand::DeliverCommand(NotinOOP& system, unsigned purchaseId)
    : system(system), purchaseId(purchaseId) {
}

void DeliverCommand::execute()
{
    try {
        Admin* admin = system.getLoggedInAdmin();
        if (admin == nullptr) {
            std::cout << "Error: Only administrators can deliver purchases!\n";
            return;
        }

        admin->deliver(purchaseId);
        std::cout << "Success: Purchase #" << purchaseId << " has been delivered.\n";
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}