#include "Buyer.h"
#include <iostream>
#include "Wishlist.h"
#include <iomanip>

Buyer::Buyer(unsigned userId, const std::string& username, const std::string& password, std::vector<std::unique_ptr<Fragrance>>& frag, std::vector<Purchase>& purchases, double balance)
		: User(userId, username, password), fragrances(frag), purchases(purchases), balance(balance) {}

Buyer* Buyer::asBuyer()
{
	return this;
}

void Buyer::addToBalance(double amount)
{
	balance += amount;
}

void Buyer::addToCart(const std::string& fragranceName)
{
	cart.add(fragranceName);
}

void Buyer::removeFromCart(const std::string& fragranceName)
{
	cart.remove(fragranceName);
}

void Buyer::addToWishlist(const std::string& fragranceName)
{
	wishlist.add(fragranceName);
}

void Buyer::removeFromWishlist(const std::string& fragranceName)
{
	wishlist.remove(fragranceName);
}

Purchase* Buyer::findPurchase(unsigned purchaseId)
{
	for (auto& p : purchases) {
		if (p.getPurchaseId() == purchaseId) {
			return &p;
		}
	}
	return nullptr;
}

void Buyer::addDiscount(std::unique_ptr<Discount> d)
{
	discounts.push_back(std::move(d));
}

// VIEW functions

void Buyer::viewCart() const
{
	cart.viewCart();
}
void Buyer::viewBought() const
{
	bool found = false;
	for (const auto& p : purchases) {
		if (p.getUserId() == this->getUserId() && p.getStatus() == PurchaseStatus::DELIVERED) {
			p.show();
			found = true;
		}
	}
	if (!found) {
		std::cout << "You have no delivered orders yet.\n";
	}
}

void Buyer::viewPurchases() const
{
	bool found = false;

	for (const auto& p : purchases) {
		if (p.getUserId() == this->getUserId()) {
			found = true;
			break;
		}
	}

	if (!found) {
		std::cout << "You have no orders placed.\n";
		return;
	}

	std::cout << "\n========= YOUR ORDER HISTORY ============\n";

	std::cout << std::left
		<< std::setw(10) << "Order ID"
		<< std::setw(15) << "Status"
		<< std::setw(15) << "Total Price"
		<< "Items Count\n";

	std::cout << "--------------------------------------------------\n";

	for (const auto& p : purchases) {
		if (p.getUserId() == this->getUserId()) {

			std::string statusStr;
			switch (p.getStatus()) {
			case PurchaseStatus::PENDING: statusStr = "PENDING"; break;
			case PurchaseStatus::DELIVERED: statusStr = "DELIVERED"; break;
			case PurchaseStatus::CANCELED: statusStr = "CANCELED"; break;
			}

			std::cout << std::left
				<< std::setw(10) << p.getPurchaseId()
				<< std::setw(15) << statusStr
				<< std::setw(15) << p.getTotalPrice()
				<< p.getBoughtFragranceNames().size() << "\n";
		}
	}
	std::cout << "--------------------------------------------------\n";
}


// Helper functions

double Buyer::getBestPriceFor(const Fragrance* f) const
{
	double bestPrice = f->getPrice();

	for (const auto& d : discounts) {
		double current = d->apply(f);
		if (current < bestPrice) {
			bestPrice = current;
		}
	}

	return bestPrice;
}

double Buyer::calculateCartTotal(std::vector<std::string>& availableItems)
{
	double sum = 0;

	std::vector<Fragrance*> validFragrances = cart.getAvailableItems(fragrances);

	for (Fragrance* f : validFragrances) {
		sum += getBestPriceFor(f);
		availableItems.push_back(f->getName());
	}

	return sum;
}

void Buyer::finalizePurchase(double totalSum, const std::vector<std::string>& boughtItems)
{
	balance -= totalSum;

	for (const std::string& name : boughtItems) {
		for (auto& frag : fragrances) {
			if (frag->getName() == name) {
				frag->removeQuantity(1);
				break;
			}
		}
	}

	Purchase newOrder(this->getUserId(), boughtItems, PurchaseStatus::PENDING, totalSum);
	purchases.push_back(newOrder);

	cart.clear();

	std::cout << "Successful payment! Total amount: " << totalSum << '\n';
}


// MAIN ACTIONS (with catalog)

void Buyer::recommend() const
{
	FragranceFamily favoriteNote = wishlist.getFavoriteNote(fragrances);

	if (favoriteNote == FragranceFamily::UNKNOWN) {
		std::cout << "Add perfumes to favorites to get recommendations!\n";
		return;
	}

	int recommendedCount = 0;
	std::cout << "Since you like this type of fragrance, we recommend:\n";

	for (const auto& frag : fragrances) {
		if (frag->getNote() == favoriteNote && !wishlist.contains(frag->getName())) {
			std::cout << "- " << frag->getName() << " (" << frag->getBrand() << ")\n";
			recommendedCount++;

			if (recommendedCount == 3) break;
		}
	}

	if (recommendedCount == 0) {
		std::cout << "Unfortunately, we have no new suggestions for your taste at the moment.\n";
	}
}

void Buyer::checkout()
{
	if (cart.isEmpty()) {
		std::cout << "Your cart is empty!\n";
		return;
	}

	std::vector<std::string> successfullyBoughtNames;

	double sum = calculateCartTotal(successfullyBoughtNames);

	if (sum > balance) {
		std::cout << "You do not have enough money in your balance for this order.\n";
		return;
	}

	finalizePurchase(sum, successfullyBoughtNames);
}

void Buyer::makeReview(const std::string& fragranceName, unsigned rating, const std::string& comment)
{
	for (auto& fragrance : fragrances) {
		if (fragrance->getName() == fragranceName) {
			
			Review r(fragranceName, this->getUserId(), comment, rating);

			fragrance->addReview(r);

			std::cout << "Your review for " << fragranceName << " has been added successfully!\n";
			return;
		}
	}
	std::cout << "Error: Perfume with name '" << fragranceName << "' not found in the store.\n";
}

void Buyer::cancel(unsigned purchaseId)
{
	Purchase* found = findPurchase(purchaseId);

	if (found != nullptr) {
		if (found->getStatus() == PurchaseStatus::PENDING) {
			found->setStatus(PurchaseStatus::CANCELED);

			balance += found->getTotalPrice();
			std::cout << "Order #" << purchaseId << " has been successfully canceled. The amount has been refunded.\n";
		}
		else {
			std::cout << "The order cannot be canceled because it has already been shipped or canceled.\n";
		}
	}
	else {
		std::cout << "An order with such an ID does not exist in your history.\n";
	}
}

void Buyer::help() const
{
	std::cout << "==================== BUYER COMMANDS =====================n"
		<< " -> add-to-cart <name>			- Adds perfume to cart\n"
		<< " -> remove-from-cart <name>     - Removes perfume from cart\n"
		<< " -> add-to-wishlist <name>		- Adds perfume to favorites\n"
		<< " -> checkout				    - Checkout cart\n"
		<< " -> recommend					- Recommends 3 perfumes\n"
		<< " -> cancel <id>					- Cancels PENDING order\n"
		<< " -> make-review <name>			- Leave a review for perfume\n"
		<< "==============================\n";
}

std::string Buyer::getRole() const
{
	return "BUYER";
}

void Buyer::save(std::ostream& out) const
{
	out << "BUYER " << getUserId() << " " << getUsername() << " "
		<< getPassword() << " " << balance << " ";

	const auto& wl = wishlist.getItems();
	out << wl.size();
	for (const auto& name : wl) out << " " << name;

	out << " " << discounts.size();
	for (const auto& d : discounts) {
		out << " ";
		d->save(out);
	}

	out << "\n";
}
