#include "AddToWishlistCommand.h"
#include <iostream>   
#include <string>     
#include <stdexcept>  

#include "System/NotinOOP.h" 
#include "Users/User.h"
#include "Users/Admin.h"
#include "Users/Buyer.h"

AddToWishlistCommand::AddToWishlistCommand(NotinOOP& system, const std::string& fragranceName)
	:system(system), fragranceName(fragranceName)
{}

void AddToWishlistCommand::execute()
{
	try {
		Buyer* buyer = system.getLoggedInBuyer();
		if (buyer == nullptr) {
			cout << "Error: Only logged-in buyers can add items to the wishlist!\n";
			return;
		}

		buyer->addToWishlist(fragranceName);
		cout << "Success: '" << fragranceName << "' was added to your wishlist.\n";
	}
	catch (const std::exception& e) {
		cout << e.what() << '\n';
	}
}
