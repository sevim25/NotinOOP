#pragma once
#include "Command.h"

class NotinOOP;

class DeliverCommand : public Command
{
    NotinOOP& system;
    unsigned purchaseId;

public:
    DeliverCommand(NotinOOP& system, unsigned purchaseId);
    void execute() override;
};