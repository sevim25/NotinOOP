#include "HelpCommand.h"
#include "System/NotinOOP.h"
#include "Users/User.h"
#include <iostream>

HelpCommand::HelpCommand(NotinOOP& system) : system(system) {}

void HelpCommand::execute()
{
    User* user = system.getLoggedInUser();

    std::cout << '\n';

    if (user == nullptr) {
        std::cout << "Available commands:\n\n"
            << "-> register <username> <password>\n"
            << "-> login <username> <password>\n"
            << "-> end\n"
            << "-> help\n";
    }
    else {
        user->help();

        //Admin::help() / Buyer::help()
    }
}