#pragma once
#include <memory>
#include <string>
#include "Command.h"

class NotinOOP;

class CommandFactory
{
public:
    static std::unique_ptr<Command> create(const std::string& line, NotinOOP& system);
};