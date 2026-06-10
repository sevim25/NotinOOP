#include <iostream>   
#include <string>     
#include <stdexcept>  

#include "System/NotinOOP.h" 
#include "Users/User.h"
#include "Users/Admin.h"
#include "Users/Buyer.h"
#include "AddToCartCommand.h"

AddToCartCommand::AddToCartCommand(NotinOOP& system, const std::string& fragranceName)
	: system(system), fragranceName(fragranceName)
{
}

void AddToCartCommand::execute()
{
	try {
		Buyer* buyer = system.getLoggedInBuyer();
		
		if (buyer == nullptr) {
			cout << "Error: Only logged-in buyers can add items to the cart!\n";
			return;
		}

		buyer->addToCart(fragranceName);
		cout << "Success: '" << fragranceName << "' was added to your cart.\n";
	}
	catch (const std::exception& e) {
		cout << e.what() << '\n';
	}
}
