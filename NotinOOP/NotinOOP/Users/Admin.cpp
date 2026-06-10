#include "Admin.h"

#include <stdexcept>
#include <iostream>

Admin::Admin(unsigned userId, const std::string& username, const std::string& password, 
	         std::vector<std::unique_ptr<Fragrance>>& fragrances, 
	         std::vector<std::unique_ptr<User>>& users, 
			 std::vector<Purchase>& purchases)

	: User(userId, username, password), fragrances(fragrances), users(users), purchases(purchases) {}

Admin* Admin::asAdmin()
{
	return this;
}


void Admin::blockUser(const std::string& username)
{
	auto it = std::find_if(users.begin(), users.end(),
		[&](const auto& u) { return u->getUsername() == username; });

	if (it == users.end()) {
		throw std::invalid_argument("Error: User not found.");
	}

	users.erase(it);
}

void Admin::createFragrance(const std::string& fragranceName, const std::string& brand,
							double price, FragranceFamily note, double quantity) 
{
	for (const auto& f : fragrances) {
		if (f->getName() == fragranceName) {
			throw std::invalid_argument("Error: Fragrance with this name already exist!");
		}
	}

	fragrances.push_back(std::make_unique<Fragrance>(fragranceName, brand, price, note, quantity));
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
			if (p.getStatus() != PurchaseStatus::PENDING) {
				throw std::invalid_argument("Error: Only PENDING orders can be delivered.");
			}
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

void Admin::help() const
{
	std::cout << "============== ADMIN COMMANDS ==================\n"
		<< "  -> block-user <username>                             - Blocks a user\n"
		<< "  -> create-fragrance <name> <brand> <price> <family>  - Adds new fragrance\n"
		<< "  -> add-quantity <fragrance-name> <quantity>          - Adds stock\n"
		<< "  -> deliver <purchase-id>                             - Marks as delivered\n"
		<< "  -> remove-review <fragrance-id> <review-id>          - Removes a review\n"
		<< "  -> logout                                            - Log out\n"
		<< "  -> help                                              - Show this menu\n"
		<< "  -> end                                               - Save and exit\n"
		<< "======================\n";
}

std::string Admin::getRole() const
{
	return "ADMIN";
}

void Admin::save(std::ostream& out) const
{
	out << "ADMIN " << getUserId() << " " << getUsername() << " " << getPassword() << "\n";
}
