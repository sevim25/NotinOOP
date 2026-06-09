#pragma once
#include <memory>
#include <optional>
#include "User.h"
#include "Cart.h"
#include "Entities/Purchase.h"
#include "Discounts/Discount.h"
#include "Wishlist.h"

class Admin : public User
{
private:
	std::vector<std::unique_ptr<Fragrance>>& fragrances;
	std::vector<std::unique_ptr<User>>& users;
	std::vector<Purchase>& purchases;

public:
	Admin(unsigned userId, const std::string& username, const std::string& password, 
		  std::vector<std::unique_ptr<Fragrance>>& fragrances,
		  std::vector<std::unique_ptr<User>>& users, 
		  std::vector<Purchase>& purchases);

	void blockUser(const std::string& username);
	void createFragrance(const std::string& fragranceName, const std::string& brand, double price);
	void addQuantity(const std::string& fragranceName, double quantity);
	void deliver(unsigned purchaseId);
	void removeReview(unsigned fragranceId, unsigned reviewId);


};