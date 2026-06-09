#pragma once
#include "FragranceFamily.h"
#include "Review.h"
#include <string>
#include <vector>


class Fragrance
{
	unsigned fragranceId;
	static unsigned nextId;

	std::string name;
	std::string brand;

	double price = 0;
	size_t quantity;

	FragranceFamily note;
	std::vector<Review> reviews;

public:
	Fragrance(unsigned fragranceId, const std::string& name, const std::string& brand, double price,
		FragranceFamily note, size_t quantity);

	Fragrance(const std::string& name, const std::string& brand, double price,
		FragranceFamily note, size_t quantity);

	unsigned getFragranceId() const;
	const std::string& getName() const;
	const std::string& getBrand() const;
	double getPrice() const;
	size_t getQuantity() const;
	FragranceFamily getNote() const;
	const std::vector<Review>& getReviews() const;

	void addReview(const Review& review);
	void removeReview(unsigned reviewId);

	void addQuantity(size_t amount);
	void removeQuantity(size_t amount);

	double getRating() const;

	static void setNextId(unsigned maxId);
};
