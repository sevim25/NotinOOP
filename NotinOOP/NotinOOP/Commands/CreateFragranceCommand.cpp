#include "CreateFragranceCommand.h"
#include "System/NotinOOP.h"
#include "Users/Admin.h"
#include <iostream>
#include <stdexcept>


CreateFragranceCommand::CreateFragranceCommand(NotinOOP& system, const std::string& name, const std::string& brand, 
                                                double price, FragranceFamily note, double quantity)
    : system(system), name(name), brand(brand), price(price), note(note), quantity(quantity)
{
}

void CreateFragranceCommand::execute()
{
    try {
        Admin* admin = system.getLoggedInAdmin();
        if (admin == nullptr) {
            std::cout << "Error: Only administrators can create fragrances!\n";
            return;
        }

        admin->createFragrance(name, brand, price, note, quantity);
        std::cout << "Success: Fragrance '" << name << "' created successfully.\n";
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}