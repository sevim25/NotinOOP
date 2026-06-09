#include "Admin.h"

#include <stdexcept>
#include <iostream>

Admin::Admin(unsigned userId, const std::string& username, const std::string& password, 
	         std::vector<std::unique_ptr<Fragrance>>& fragrances, 
	         std::vector<std::unique_ptr<User>>& users, 
			 std::vector<Purchase>& purchases)

	: User(userId, username, password), fragrances(fragrances), users(users), purchases(purchases) {}

void Admin::blockUser(const std::string& username)
{
	for (const auto& user : users) {
		if (user->getUsername() == username) {
			user->setBlocked(true);
			return;
		}
	}
	throw std::invalid_argument("Error: User not found.");
}

void Admin::createFragrance(const std::string& fragranceName, const std::string& brand, double price)
{
	for (const auto& f : fragrances) {
		if (f->getName() == fragranceName) {
			throw std::invalid_argument("Error: Fragrance with this name already exist!");
		}
	}

	fragrances.push_back(std::make_unique<Fragrance>(fragranceName, brand, price));
}

void Admin::addQuantity(const std::string& fragranceName, double quantity)
{
	if (quantity < 0) {
		throw std::invalid_argument("Error: The quantity must be positive number!");
	}

	for (const auto& f : fragrances) {
		if (f->getName() == fragranceName) {
			f->addQuantity(quantity);
			return;
		}
	}

	throw std::invalid_argument("Fragrance is not found.");
}

void Admin::deliver(unsigned purchaseId)
{
	for (auto& p : purchases) {
		if (p.getPurchaseId() == purchaseId) {
			p.setStatus(PurchaseStatus::DELIVERED);
			return;
		}
	}
	throw std::invalid_argument("Error: Purchase ID not found.");
}

void Admin::removeReview(unsigned fragranceId, unsigned reviewId)
{
	for (const auto& f : fragrances) {
		if (f->getFragranceId() == fragranceId) {

			unsigned authorId = f->getReviewAuthorId(reviewId);
			f->removeReview(reviewId);

			for (const auto& user : users) {
				if (user->getUserId() == authorId) {
					user->applyReviewRemovalPenalty();
					break;
				}
			}

			return;
		}
	}
	throw std::invalid_argument("Error: Fragrance ID not found.");
}
