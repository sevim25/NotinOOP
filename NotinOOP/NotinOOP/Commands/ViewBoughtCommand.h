#pragma once
#include "Command.h"

class NotinOOP;

class ViewBoughtCommand : public Command
{
    NotinOOP& system;

public:
    ViewBoughtCommand(NotinOOP& system);
    void execute() override;
};