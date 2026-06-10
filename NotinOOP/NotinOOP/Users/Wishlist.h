#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Entities/FragranceFamily.h"
#include "Entities/fragrance.h"

class Wishlist 
{
private:
	std::vector<std::string> items;

public: 
	void add(const std::string& fragranceName);
	void remove(const std::string& fragranceName);

	bool contains(const std::string& fragranceName) const;

	const std::vector<std::string>& getItems() const;

	FragranceFamily getFavoriteNote(const std::vector<std::unique_ptr<Fragrance>>& catalog) const;
};