#include "RemoveFromCartCommand.h"

#include <iostream>   
#include <string>     
#include <stdexcept>  

#include "System/NotinOOP.h" 
#include "Users/User.h"
#include "Users/Admin.h"
#include "Users/Buyer.h"
#include "AddToCartCommand.h"


RemoveFromCartCommand::RemoveFromCartCommand(NotinOOP& system, const std::string& fragranceName)
	: system(system), fragranceName(fragranceName)
{
}

void RemoveFromCartCommand::execute()
{
	try {
		Buyer* buyer = system.getLoggedInBuyer();

		if (buyer == nullptr) {
			cout << "Error: Only logged-in buyers can remove items from the cart!\n";
			return;
		}

		buyer->removeFromCart(fragranceName);
		cout << "Success: '" << fragranceName << "' was removed from your cart.\n";
	}
	catch (const std::exception& e) {
		cout << e.what() << '\n';
	}
}
