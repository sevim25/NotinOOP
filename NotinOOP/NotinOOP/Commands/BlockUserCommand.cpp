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
		User* current = system.getLoggedInUser();

		if (current == nullptr || current->getRole() == "ADMIN") {
			cout << "Error: Only admins can block users!";
			return;
		}

		Admin* admin = dynamic_cast<Admin*>(current);
		admin->blockUser(username);

		cout << "User " << username << " was successfully blocked.\n";
		
	}
	catch (const std::exception& e) {
		cout << e.what() << '\n';
	}
}
