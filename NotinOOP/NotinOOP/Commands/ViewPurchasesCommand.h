#pragma once
#include "Command.h"

class NotinOOP;

class ViewPurchasesCommand : public Command
{
    NotinOOP& system;

public:
    ViewPurchasesCommand(NotinOOP& system);
    void execute() override;
};