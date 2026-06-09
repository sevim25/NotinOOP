#include "NotinOOP.h"
#include "Users/Buyer.h"
#include <stdexcept>

NotinOOP::NotinOOP() : loggedUser(nullptr)
{
}

void NotinOOP::registerBuyer(const std::string& username, const std::string& password)
{
	for (const auto& u : users) {
		if (u->getUsername() == username) {
			throw std::invalid_argument("Error: Username is already taken.");
		}
	}

	unsigned newUserId = users.size() + 1;
	users.push_back(std::make_unique<Buyer>(newUserId, username, password, fragrances, purchases));
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
}

User* NotinOOP::getLoggedInUser() const
{
	return loggedUser;
}

void NotinOOP::run()
{

}
