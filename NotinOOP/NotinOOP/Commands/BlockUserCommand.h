#pragma once
#include "Command.h"
#include "System/NotinOOP.h"
#include <string>

class BlockUserCommand : public Command
{
	NotinOOP& system;
	std::string username;

public:
	BlockUserCommand(NotinOOP& system, const std::string& username);

	void execute() override;
};