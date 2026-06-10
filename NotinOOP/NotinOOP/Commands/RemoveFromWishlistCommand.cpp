#include "RemoveFromWishlistCommand.h"
#include "System/NotinOOP.h"
#include "Users/Buyer.h"
#include <iostream>
#include <stdexcept>

RemoveFromWishlistCommand::RemoveFromWishlistCommand(NotinOOP& system, const std::string& fragranceName)
    : system(system), fragranceName(fragranceName) {
}

void RemoveFromWishlistCommand::execute()
{
    try {
        Buyer* buyer = system.getLoggedInBuyer();
        if (buyer == nullptr) {
            std::cout << "Error: Only logged-in buyers can manage their wishlist!\n";
            return;
        }

        buyer->removeFromWishlist(fragranceName);
        std::cout << "Success: '" << fragranceName << "' was removed from your wishlist.\n";
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}