#pragma once
#include "Command.h"
#include "System/NotinOOP.h"
#include <string>

class AddToCartCommand : public Command
{
	NotinOOP& system;
	std::string fragranceName;

public:
	AddToCartCommand(NotinOOP& system, const std::string& fragranceName);

	void execute() override;
};