#pragma once
#include "Command.h"
#include "System/NotinOOP.h"
#include <string>

class RemoveFromCartCommand : public Command
{
	NotinOOP& system;
	std::string fragranceName;

public:
	RemoveFromCartCommand(NotinOOP& system, const std::string& fragranceName);

	void execute() override;
};