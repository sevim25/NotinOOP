#pragma once
#include "Command.h"
#include <string>

class NotinOOP;

class RemoveFromWishlistCommand : public Command
{
    NotinOOP& system;
    std::string fragranceName;

public:
    RemoveFromWishlistCommand(NotinOOP& system, const std::string& fragranceName);
    void execute() override;
};