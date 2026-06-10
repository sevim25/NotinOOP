#pragma once
#include "Command.h"

class NotinOOP;

class HelpCommand : public Command
{
    NotinOOP& system;

public:
    HelpCommand(NotinOOP& system);
    void execute() override;
};