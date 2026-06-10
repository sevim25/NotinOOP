#pragma once
#include "Command.h"
#include <string>

class NotinOOP;

class LoginCommand : public Command
{
    NotinOOP& system;
    std::string username;
    std::string password;

public:
    LoginCommand(NotinOOP& system, const std::string& username, const std::string& password);
    void execute() override;
};