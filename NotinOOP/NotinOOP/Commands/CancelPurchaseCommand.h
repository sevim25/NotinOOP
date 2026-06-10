#pragma once
#include "Command.h"

class NotinOOP;

class CancelPurchaseCommand : public Command
{
    NotinOOP& system;
    unsigned purchaseId;

public:
    CancelPurchaseCommand(NotinOOP& system, unsigned purchaseId);
    void execute() override;
};