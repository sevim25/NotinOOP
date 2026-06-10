#include <iostream>   
#include <string>     
#include <stdexcept>  

#include "System/NotinOOP.h" 
#include "Users/User.h"
#include "Users/Admin.h"
#include "Users/Buyer.h"

#include "ExitCommand.h"
#include <cstdlib>

void ExitCommand::execute()
{
    std::cout << "Shutting down the system. Goodbye!\n";
    std::exit(0);
}