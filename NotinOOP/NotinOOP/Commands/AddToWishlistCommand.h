#pragma once
#include "Command.h"
#include "System/NotinOOP.h"
#include <string>

class AddToWishlistCommand : public Command
{
	NotinOOP& system;
	std::string fragranceName;


public:
	AddToWishlistCommand(NotinOOP& system, const std::string& fragranceName);

	void execute() override;
};