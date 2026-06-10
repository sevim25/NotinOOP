#include "NotinOOP.h"
#include "Users/Buyer.h"
#include "Discounts/BonusDiscount.h"
#include "Discounts/BrandDiscount.h"
#include <stdexcept>
#include <iostream>

#include "Commands/CommandFactory.h"

NotinOOP::NotinOOP() : loggedUser(nullptr), loggedAdmin(nullptr), loggedBuyer(nullptr) 
{
    loadFromFile("notinOOP.txt");

    if (users.empty()) {
	    users.push_back(std::make_unique<Admin>(1, "admin", "admin123", fragrances, users, purchases));
    }
}

void NotinOOP::registerBuyer(const std::string& username, const std::string& password)
{
	for (const auto& u : users) {
		if (u->getUsername() == username) {
			throw std::invalid_argument("Error: Username is already taken.");
		}
	}

	unsigned newUserId = users.size() + 1;
	users.push_back(std::make_unique<Buyer>(newUserId, username, password, fragrances, purchases,0));
}

void NotinOOP::login(const std::string& username, const std::string& password)
{
	if (loggedUser != nullptr) {
		throw std::runtime_error("Error: Someone is already logged in. Please logout first.");
	}

	for (const auto& u : users) {
		if (u->getUsername() == username && u->getPassword() == password) {
			if (u->getIsBlocked()) {
				throw std::runtime_error("Error: This account is blocked by an administrator!");
			}

			loggedUser = u.get();

			loggedAdmin = u->asAdmin();
			loggedBuyer = u->asBuyer();

			return;
		}
	}
	throw std::invalid_argument("Error: Invalid username or password.");
}

void NotinOOP::logout()
{
	if (loggedUser == nullptr) {
		throw std::runtime_error("Error: No user is currently logged in.");
	}

	loggedUser = nullptr;
	loggedAdmin = nullptr;
	loggedBuyer = nullptr;
}

User* NotinOOP::getLoggedInUser() const
{
	return loggedUser;
}

Admin* NotinOOP::getLoggedInAdmin() const
{
	return loggedAdmin;
}

Buyer* NotinOOP::getLoggedInBuyer() const
{
	return loggedBuyer;
}

void NotinOOP::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) {
        std::cout << "Error: Could not open database file for writing.\n";
        return;
    }

    out << "#FRAGRANCES\n";
    for (const auto& f : fragrances) {
        f->save(out);
    }

    out << "#USERS\n";
    for (const auto& u : users) {
        u->save(out);
    }

    out << "#PURCHASES\n";
    for (const auto& p : purchases) {
        p.save(out);
    }
}

void NotinOOP::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) return; 

    std::string line;
    std::string currentSection = "";

    while (in >> line) {
        if (line == "#FRAGRANCES" || line == "#USERS" || line == "#PURCHASES") {
            currentSection = line;
            continue;
        }

        if (currentSection == "#FRAGRANCES") {
            unsigned id; double price, qty; std::string name, brand, familyStr;
            size_t reviewsCount;

            id = std::stoul(line);
            in >> name >> brand >> price >> familyStr >> qty >> reviewsCount;

            auto f = std::make_unique<Fragrance>(id, name, brand, price, fromString(familyStr), qty);

            for (size_t i = 0; i < reviewsCount; ++i) {
                unsigned revId, userId, rating;
                std::string comment;

                in >> revId >> userId >> rating >> comment;
                for (char& c : comment) if (c == '_') c = ' ';

                f->addReview(Review(revId, name, userId, comment, rating));
                Review::setNextId(revId); 
            }

            Fragrance::setNextId(id);
            fragrances.push_back(std::move(f));
        }
        else if (currentSection == "#USERS") {
            std::string role = line;
            unsigned id; std::string user, pass;

            in >> id >> user >> pass;

            if (role == "ADMIN") {
                users.push_back(std::make_unique<Admin>(id, user, pass, fragrances, users, purchases));
            }
            else if (role == "BUYER") {
                double balance;
                size_t wishlistCount;
                in >> balance >> wishlistCount;

                auto b = std::make_unique<Buyer>(id, user, pass, fragrances, purchases, balance);

                // wishlist
                for (size_t i = 0; i < wishlistCount; i++) {
                    std::string name;
                    in >> name;
                    b->addToWishlist(name);
                }
                User::setNextId(id + 1);
                users.push_back(std::move(b));

                //Discounts

                size_t discountsCount;
                in >> discountsCount;
                for (size_t i = 0; i < discountsCount; i++) {
                    std::string type; double percent;
                    in >> type >> percent;
                    if (type == "BONUS") {
                        double bonus; in >> bonus;
                        b->addDiscount(std::make_unique<BonusDiscount>(percent, bonus));
                    }
                    else if (type == "BRAND") {
                        std::string brand; in >> brand;
                        b->addDiscount(std::make_unique<BrandDiscount>(percent, brand));
                    }
                    else {
                        b->addDiscount(std::make_unique<Discount>(percent));
                    }
                }

            }
        }
        else if (currentSection == "#PURCHASES") {
            unsigned id, userId; int statusInt; double price; size_t itemsCount;

            id = std::stoul(line);
            in >> userId >> statusInt >> price >> itemsCount;

            std::vector<std::string> items;
            for (size_t i = 0; i < itemsCount; i++) {
                std::string itemName;
                in >> itemName;
                items.push_back(itemName);
            }

            PurchaseStatus status = static_cast<PurchaseStatus>(statusInt);
            purchases.push_back(Purchase(id, userId, items, status, price));
            Purchase::setNextId(id);
        }
    }
}

void NotinOOP::run()
{
    std::cout << "=================================================\n";
    std::cout << "          Welcome to NotinOOP!             \n";
    std::cout << " Type 'help' to see the list of available commands.\n";
    std::cout << "=================================================\n";

	std::string cmd;
    bool isRunning = true;

    std::cout << "> ";

	while (isRunning && std::cin >> cmd) {

        if (cmd == "end") {
            isRunning = false;
            break;
        }

		try {
			std::unique_ptr<Command> command = CommandFactory::create(cmd, (*this));
			
			if (command) {
				command->execute();
			}
		}
		catch (const std::exception& e) {
			std::cout <<" [!] " << e.what() << '\n';
		}

        if (isRunning) {
            std::cout << '\n';
        }
	}

    saveToFile("notinOOP.txt");
    std::cout << "\nData saved successfully. Exiting...\n";
}

