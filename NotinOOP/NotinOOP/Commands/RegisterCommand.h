#pragma once
#include "Command.h"
#include "System/NotinOOP.h"
#include <string>

class RegisterCommand : public Command
{
	NotinOOP& system;
	std::string username;
	std::string password;

public:
	RegisterCommand(NotinOOP& system, const std::string& username, const std::string& password);

	void execute() override;
};