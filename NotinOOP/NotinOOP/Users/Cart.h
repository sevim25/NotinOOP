#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Entities/Fragrance.h"

class Cart
{
	std::vector<std::string> items;

public:

	void add(const std::string& fragranceName);
	void remove(const std::string& fragranceName);

	void clear();
	bool isEmpty()const;

	void viewCart() const;

	const std::vector<std::string>& getItems() const;
	std::vector<Fragrance*> getAvailableItems(std::vector<std::unique_ptr<Fragrance>>& catalog);
};