#pragma once
#include "Entities/Fragrance.h"
#include "Entities/Purchase.h"

class User 
{
	unsigned userId;
	std::string username;
	std::string password;

	bool isBlocked = false;
	unsigned removedReviewsCount = 0;

	static constexpr unsigned MAX_REMOVED_REVIEWS = 7;

public: 
	User(unsigned userId, const std::string& username, const std::string& password);
	unsigned getUserId() const;
	const std::string& getUsername() const;
	const std::string& getPassword() const;

	bool checkPassword(const std::string& pass) const;

	bool getIsBlocked() const;
	void setBlocked(bool status);

	bool applyReviewRemovalPenalty();

	virtual void help() const = 0;
	virtual std::string getRole() const = 0;

	virtual ~User() = default;

};