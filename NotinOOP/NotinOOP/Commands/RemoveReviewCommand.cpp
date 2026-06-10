#include <iostream>   
#include <string>     
#include <stdexcept>  

#include "System/NotinOOP.h" 
#include "Users/User.h"
#include "Users/Admin.h"
#include "Users/Buyer.h"
#include "RemoveReviewCommand.h"

RemoveReviewCommand::RemoveReviewCommand(NotinOOP& system, unsigned fragranceId, unsigned reviewId)
	: system(system), fragranceId(fragranceId), reviewId(reviewId)
{
}

void RemoveReviewCommand::execute()
{
	try {
		Admin* admin = system.getLoggedInAdmin();
		if (admin == nullptr) {
			cout << "Error: Only administrators can remove reviews!\n";
			return;
		}

		admin->removeReview(fragranceId, reviewId);
		cout << "Success: Review #" << reviewId << " from fragrance #" << fragranceId << " has been removed.\n";
	}
	catch (const std::exception& e) {
		cout << e.what() << '\n';
	}
}
