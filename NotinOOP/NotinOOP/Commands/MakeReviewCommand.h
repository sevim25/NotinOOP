#pragma once
#include "Command.h"
#include <string>

class NotinOOP;

class MakeReviewCommand : public Command
{
    NotinOOP& system;
    std::string fragranceName;
    unsigned rating;
    std::string comment;

public:
    MakeReviewCommand(NotinOOP& system, const std::string& fragranceName, unsigned rating, const std::string& comment);
    void execute() override;
};