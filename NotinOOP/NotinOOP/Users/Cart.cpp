#include "Cart.h"
#include <iostream>
#include <memory>
#include "Buyer.h"

void Cart::add(const std::string& fragranceName)
{
	items.push_back(fragranceName);
}

void Cart::remove(const std::string& fragranceName)
{
	std::erase(items, fragranceName);
}

void Cart::clear()
{
	items.clear();
}

bool Cart::isEmpty() const
{
	return items.empty();
}


const std::vector<std::string>& Cart::getItems() const
{
	return items;
}

std::vector<Fragrance*> Cart::getAvailableItems(std::vector<std::unique_ptr<Fragrance>>& catalog)
{
	std::vector<Fragrance*> avaible;
	std::vector<std::string> stillInStock;

	for (const auto& item : items) {
		bool found = false;

		for (auto& fragrance : catalog) {
			if (fragrance->getName() == item) 
			{
				avaible.push_back(fragrance.get());
				stillInStock.push_back(item);
				found = true;
				break;
			}
		}

		if (!found) {
			std::cout << "Perfume " << item << " is no longer available and has been removed from the cart.\n";
		}
	}

	items = stillInStock;

	return avaible;
}

void Cart::viewCart() const
{
	std::cout << "--- Cart ---\n";
	for (const auto& i : items) {
		std::cout << i << '\n';
	}
}