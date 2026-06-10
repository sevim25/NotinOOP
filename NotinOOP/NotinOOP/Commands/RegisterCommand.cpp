#include "RegisterCommand.h"
#include <iostream>
#include <stdexcept>

RegisterCommand::RegisterCommand(NotinOOP& system, const std::string& username, const std::string& password)
	: system(system), username(username), password(password) {}

void RegisterCommand::execute()
{
	try {
		system.registerBuyer(username, password);

		std::cout << "Success: User '" << username << "' was registered successfully!\n";
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
}
