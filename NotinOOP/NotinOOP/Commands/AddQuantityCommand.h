#pragma once
#include "Command.h"
#include "System/NotinOOP.h"
#include <string>

class AddQuantityCommand : public Command
{
	NotinOOP& system;
	std::string fragranceName;
	double quantity;

public:
	AddQuantityCommand(NotinOOP& system, const std::string& fragranceName, double quantity);

	void execute() override;
};