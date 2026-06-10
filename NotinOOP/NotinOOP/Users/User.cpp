#include "User.h"

User::User(unsigned userId, const std::string& username, const std::string& password)
	: userId(userId), username(username), password(password) {}

const std::string& User::getUsername() const
{
	return username;
}

const std::string& User::getPassword() const
{
	return password;
}

bool User::checkPassword(const std::string& pass) const
{
	return password == pass;
}

bool User::getIsBlocked() const
{
	return isBlocked;
}

void User::setBlocked(bool status)
{
	isBlocked = status;
}

bool User::applyReviewRemovalPenalty()
{
	removedReviewsCount++;
	if (removedReviewsCount >= MAX_REMOVED_REVIEWS && !isBlocked) {
		isBlocked = true;
		return true;
	}

	return false;
}

unsigned User::getUserId() const
{
	return userId;
}

Admin* User::asAdmin()
{
	return nullptr;
}

Buyer* User::asBuyer()
{
	return nullptr;
}
