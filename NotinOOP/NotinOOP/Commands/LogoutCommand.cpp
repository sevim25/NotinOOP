#include <iostream>   
#include <string>     
#include <stdexcept>  

#include "System/NotinOOP.h" 
#include "Users/User.h"
#include "Users/Admin.h"
#include "Users/Buyer.h"
#include "LogoutCommand.h"

LogoutCommand::LogoutCommand(NotinOOP& system) : system(system) {}

void LogoutCommand::execute()
{
    try {
        system.logout();
        std::cout << "Success: Logged out successfully.\n";
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}