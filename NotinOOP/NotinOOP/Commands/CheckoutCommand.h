#pragma once
#include "Command.h"

class NotinOOP;

class CheckoutCommand : public Command
{
    NotinOOP& system;

public:
    CheckoutCommand(NotinOOP& system);
    void execute() override;
};