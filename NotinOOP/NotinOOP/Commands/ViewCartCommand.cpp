#include <iostream>   
#include <string>     
#include <stdexcept>  

#include "System/NotinOOP.h" 
#include "Users/User.h"
#include "Users/Admin.h"
#include "Users/Buyer.h"

#include "ViewCartCommand.h"


ViewCartCommand::ViewCartCommand(NotinOOP& system) : system(system) {}

void ViewCartCommand::execute()
{
    try {
        Buyer* buyer = system.getLoggedInBuyer();
        if (buyer == nullptr) {
            std::cout << "Error: Only logged-in buyers can view the cart!\n";
            return;
        }

        buyer->viewCart();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}