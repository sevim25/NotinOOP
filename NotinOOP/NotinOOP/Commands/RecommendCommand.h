#pragma once
#include "Command.h"

class NotinOOP;

class RecommendCommand : public Command
{
    NotinOOP& system;

public:
    RecommendCommand(NotinOOP& system);
    void execute() override;
};