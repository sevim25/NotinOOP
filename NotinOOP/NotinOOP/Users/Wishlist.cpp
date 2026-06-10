#include "Wishlist.h"
#include <stdexcept>

void Wishlist::add(const std::string& fragranceName)
{
	if (contains(fragranceName)) {
		throw std::invalid_argument("Error: '" + fragranceName + "' is already in your wishlist.");
	}
	items.push_back(fragranceName);
}

void Wishlist::remove(const std::string& fragranceName)
{
	std::erase(items, fragranceName);
}

bool Wishlist::contains(const std::string& fragranceName) const
{
	for (const auto& i : items) {
		if (i == fragranceName) {
			return true;
		}
	}
	return false;
}

FragranceFamily Wishlist::getFavoriteNote(const std::vector<std::unique_ptr<Fragrance>>& catalog) const 
{
	size_t floral = 0, woody = 0, fresh = 0, oriental = 0;

	for (const auto& name : items) {
		for (const auto& fragrance : catalog) {
			if (fragrance->getName() == name) 
				{
					switch (fragrance->getNote()) {
					case FragranceFamily::FLORAL:   floral++; break;
					case FragranceFamily::WOODY:    woody++; break;
					case FragranceFamily::FRESH:    fresh++; break;
					case FragranceFamily::ORIENTAL: oriental++; break;
					default: break;
					}
					break;
			}
		}
	}

	FragranceFamily favNote = FragranceFamily::UNKNOWN;

	size_t maxCount = 0;

	if (floral > maxCount) {
		maxCount = floral;
		favNote = FragranceFamily::FLORAL;
	}
	if (woody > maxCount) {
		maxCount = woody;
		favNote = FragranceFamily::WOODY;
	}
	if (fresh > maxCount) {
		maxCount = fresh;
		favNote = FragranceFamily::FRESH;
	}
	if (oriental > maxCount) {
		maxCount = oriental;
		favNote = FragranceFamily::ORIENTAL;
	}

	return favNote;
}

const std::vector<std::string>& Wishlist::getItems() const {
	return items;
}
