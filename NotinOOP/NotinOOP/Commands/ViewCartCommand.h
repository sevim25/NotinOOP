#pragma once
#include "Command.h"

class NotinOOP;

class ViewCartCommand : public Command
{
    NotinOOP& system;

public:
    ViewCartCommand(NotinOOP& system);
    void execute() override;
};