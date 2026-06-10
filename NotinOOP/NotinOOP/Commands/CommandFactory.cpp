#include "CommandFactory.h"

#include "LoginCommand.h"
#include "LogoutCommand.h"
#include "RegisterCommand.h"
#include "HelpCommand.h"
#include "AddToCartCommand.h"
#include "RemoveFromCartCommand.h"
#include "AddToWishlistCommand.h"
#include "RemoveFromWishlistCommand.h"
#include "AddToBalanceCommand.h"
#include "ViewCartCommand.h"
#include "ViewBoughtCommand.h"
#include "ViewPurchasesCommand.h"
#include "CheckoutCommand.h"
#include "CancelPurchaseCommand.h"
#include "MakeReviewCommand.h"
#include "RecommendCommand.h"
#include "BlockUserCommand.h"
#include "CreateFragranceCommand.h"
#include "AddQuantityCommand.h"
#include "DeliverCommand.h"
#include "RemoveReviewCommand.h"

std::unique_ptr<Command> CommandFactory::create(const std::string& cmd, NotinOOP& system)
{
	if (cmd == "register") {
		std::string username, password;
		std::cin >> username >> password;

		return std::make_unique< RegisterCommand>(system, username, password);
	}

	if (cmd == "login") {
		std::string username, password;
		std::cin >> username >> password;

		return std::make_unique<LoginCommand>(system, username, password);
	}

	if (cmd == "logout") return std::make_unique<LogoutCommand>(system);
	if (cmd == "help")   return std::make_unique<HelpCommand>(system);


	// buyer

    if (cmd == "add-to-cart") {
        std::string name;
        std::cin >> name;

        return std::make_unique<AddToCartCommand>(system, name);
    }

    if (cmd == "remove-from-cart") {
        std::string name;
        std::cin >> name;

        return std::make_unique<RemoveFromCartCommand>(system, name);
    }

    if (cmd == "add-to-wishlist") {
        std::string name;
        std::cin >> name;

        return std::make_unique<AddToWishlistCommand>(system, name);
    }

    if (cmd == "remove-from-wishlist") {
        std::string name;
        std::cin >> name;

        return std::make_unique<RemoveFromWishlistCommand>(system, name);
    }

    if (cmd == "add-to-balance") {
        double amount;
        std::cin >> amount;

        return std::make_unique<AddToBalanceCommand>(system, amount);
    }

    if (cmd == "view-cart") {
        return std::make_unique<ViewCartCommand>(system);
    }

    if (cmd == "view-bought") {
        return std::make_unique<ViewBoughtCommand>(system);
    }

    if (cmd == "view-purchases") {
        return std::make_unique<ViewPurchasesCommand>(system);
    }

    if (cmd == "checkout") {
        return std::make_unique<CheckoutCommand>(system);
    }

    if (cmd == "recommend") {
        return std::make_unique<RecommendCommand>(system);
    }

    if (cmd == "cancel") {
        unsigned id;
        std::cin >> id;

        return std::make_unique<CancelPurchaseCommand>(system, id);
    }

    if (cmd == "make-review") {
        std::string name, comment;
        unsigned rating;

        std::cin >> name >> rating;
        std::cin.ignore();
        std::getline(std::cin, comment);

        return std::make_unique<MakeReviewCommand>(system, name, rating, comment);
    }

    // admin

    if (cmd == "block-user") {
        std::string username;
        std::cin >> username;

        return std::make_unique<BlockUserCommand>(system, username);
    }
    if (cmd == "create-fragrance") {
        std::string name, brand, family;
        double price, quantity;

        std::cin >> name >> brand >> price >> family >> quantity;

        return std::make_unique<CreateFragranceCommand>(system, name, brand, price, fromString(family), quantity);
    }
    if (cmd == "add-quantity") {
        std::string name;
        double quantity;

        std::cin >> name >> quantity;

        return std::make_unique<AddQuantityCommand>(system, name, quantity);
    }
    if (cmd == "deliver") {
        unsigned id;
        std::cin >> id;

        return std::make_unique<DeliverCommand>(system, id);
    }
    if (cmd == "remove-review") {
        unsigned fragranceId, reviewId;

        std::cin >> fragranceId >> reviewId;

        return std::make_unique<RemoveReviewCommand>(system, fragranceId, reviewId);
    }

    throw std::invalid_argument("Unknown command: " + cmd);
}
