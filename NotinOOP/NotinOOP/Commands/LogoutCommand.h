#pragma once
#include "Command.h"

class NotinOOP;

class LogoutCommand : public Command
{
    NotinOOP& system;

public:
    LogoutCommand(NotinOOP& system);
    void execute() override;
};