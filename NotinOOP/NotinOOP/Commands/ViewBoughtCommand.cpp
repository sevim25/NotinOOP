#include "ViewBoughtCommand.h"
#include "System/NotinOOP.h"
#include "Users/Buyer.h"
#include <iostream>
#include <stdexcept>

ViewBoughtCommand::ViewBoughtCommand(NotinOOP& system) : system(system) {}

void ViewBoughtCommand::execute()
{
    try {
        Buyer* buyer = system.getLoggedInBuyer();
        if (buyer == nullptr) {
            std::cout << "Error: Only logged-in buyers can view bought items!\n";
            return;
        }

        buyer->viewBought();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}