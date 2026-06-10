#pragma once
#include "Command.h"
#include "System/NotinOOP.h"
#include <string>

class AddToBalanceCommand : public Command
{
	NotinOOP& system;
	double amount;

public:
	AddToBalanceCommand(NotinOOP& system, double amount);

	void execute() override;
};