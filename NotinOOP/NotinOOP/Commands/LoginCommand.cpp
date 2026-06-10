#include <iostream>   
#include <string>     
#include <stdexcept>  

#include "System/NotinOOP.h" 
#include "LoginCommand.h"

LoginCommand::LoginCommand(NotinOOP& system, const std::string& username, const std::string& password)
    : system(system), username(username), password(password) {
}

void LoginCommand::execute()
{
    try {
        system.login(username, password);
        std::cout << "Success: Welcome back, " << username << "!\n";
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
