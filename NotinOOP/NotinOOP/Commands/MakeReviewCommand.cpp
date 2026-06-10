#include <iostream>   
#include <string>     
#include <stdexcept>  

#include "System/NotinOOP.h" 
#include "Users/User.h"
#include "Users/Admin.h"
#include "Users/Buyer.h"

#include "MakeReviewCommand.h"


MakeReviewCommand::MakeReviewCommand(NotinOOP& system, const std::string& fragranceName, unsigned rating, const std::string& comment)
    : system(system), fragranceName(fragranceName), rating(rating), comment(comment) {
}

void MakeReviewCommand::execute()
{
    try {
        Buyer* buyer = system.getLoggedInBuyer();
        if (buyer == nullptr) {
            std::cout << "Error: Only logged-in buyers can submit reviews!\n";
            return;
        }

        buyer->makeReview(fragranceName, rating, comment);
        std::cout << "Success: Review submitted for '" << fragranceName << "'.\n";
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}