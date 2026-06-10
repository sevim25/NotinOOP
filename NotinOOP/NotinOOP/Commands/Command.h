#pragma once
#include <stdexcept>
#include <iostream>

using std::cout;

class Command
{
public:
	virtual void execute() = 0;
	virtual ~Command() = default;
};