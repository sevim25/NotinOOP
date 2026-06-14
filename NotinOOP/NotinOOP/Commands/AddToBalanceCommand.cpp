#include "AddToBalanceCommand.h"

#include <iostream>   
#include <string>     
#include <stdexcept>  

#include "System/NotinOOP.h" 
#include "Users/User.h"
#include "Users/Admin.h"
#include "Users/Buyer.h"

AddToBalanceCommand::AddToBalanceCommand(NotinOOP& system, double amount) 
	: system(system), amount(amount)
{
}

void AddToBalanceCommand::execute()
{
	try {
		Buyer* buyer = system.getLoggedInBuyer();
		if (buyer == nullptr) {
			cout << "Error: Only buyers can add amount to their balance!\n";
			return;
		}

		buyer->addToBalance(amount);
		cout << "Success: Added " << amount << " to balance.\n";
	}
	catch (const std::exception& e) {
		cout << e.what() << '\n';
	}
}
