#include <iostream>   
#include <string>     
#include <stdexcept>  

#include "System/NotinOOP.h" 
#include "Users/User.h"
#include "Users/Admin.h"
#include "Users/Buyer.h"

#include "RecommendCommand.h"


RecommendCommand::RecommendCommand(NotinOOP& system) : system(system) {}

void RecommendCommand::execute()
{
    try {
        Buyer* buyer = system.getLoggedInBuyer();
        if (buyer == nullptr) {
            std::cout << "Error: Only logged-in buyers can view recommendations!\n";
            return;
        }

        buyer->recommend();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}