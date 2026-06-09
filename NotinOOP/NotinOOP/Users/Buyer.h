#pragma once
#include <memory>
#include <optional>
#include "User.h"
#include "Cart.h"
#include "Entities/Purchase.h"
#include "Discounts/Discount.h"
#include "Wishlist.h"

class Buyer : public User
{
	Cart cart;
	Wishlist wishlist;

	std::vector<Purchase>& purchases;
	std::vector<std::unique_ptr<Fragrance>>& fragrances;

	std::vector<std::unique_ptr<Discount>> discounts;

	double balance = 0;

	double getBestPriceFor(const Fragrance* f) const;
	double calculateCartTotal(std::vector<std::string>& availableItems);

	void finalizePurchase(double totalSum, const std::vector<std::string>& boughtItems);
										
public:
	Buyer(unsigned userId, const std::string& username, const std::string& password, 
		  std::vector<std::unique_ptr<Fragrance>>& fragrances, std::vector<Purchase>& purchases, double balance);
	
	void addToBalance(double amount);

	void addToCart(const std::string& fragranceName);
	void removeFromCart(const std::string& fragranceName);

	void addToWishlist(const std::string& fragranceName);
	void removeFromWishlist(const std::string& fragranceName);

	void viewCart() const;
	void viewBought() const;
	void viewPurchases() const;

	void cancel(unsigned purchaseId);
	void recommend() const;
	void checkout();
	void makeReview(const std::string& fragranceName, unsigned rating, const std::string& comment);

	void help() const override;
	std::string getRole() const override;

	Purchase* findPurchase(unsigned purchaseId);
};