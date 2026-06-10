#include <iostream>   
#include <string>     
#include <stdexcept>  

#include "System/NotinOOP.h" 
#include "Users/User.h"
#include "Users/Admin.h"
#include "Users/Buyer.h"
#include "AddQuantityCommand.h"

AddQuantityCommand::AddQuantityCommand(NotinOOP& system, const std::string& fragranceName, double quantity)
	: system(system), fragranceName(fragranceName), quantity(quantity)
{
}

void AddQuantityCommand::execute()
{
	try {
		Admin* admin = system.getLoggedInAdmin();

		if (admin == nullptr) {
			cout << "Error: Only administrators can add fragrance quantity!\n";
			return;
		}

		admin->addQuantity(fragranceName, quantity);

		cout << "Success: Added quantity.\n";
	}
	catch (const std::exception& e) {
		cout << e.what() << '\n';
	}
}
