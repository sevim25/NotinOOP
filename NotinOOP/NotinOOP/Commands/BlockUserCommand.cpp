#include "BlockUserCommand.h"
#include <iostream>   
#include <string>     
#include <stdexcept>  

#include "System/NotinOOP.h" 
#include "Users/User.h"
#include "Users/Admin.h"
#include "Users/Buyer.h"

BlockUserCommand::BlockUserCommand(NotinOOP& system, const std::string& username)
	: system(system), username(username) {}

void BlockUserCommand::execute()
{
	try {
		Admin* admin = system.getLoggedInAdmin();
		if (admin == nullptr) {
			cout << "Error: Only admins can block users!\n";
			return;
		}

		admin->blockUser(username);

		cout << "User " << username << " was successfully blocked.\n";
		
	}
	catch (const std::exception& e) {
		cout << e.what() << '\n';
	}
}
