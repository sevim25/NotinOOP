#pragma once
#include "FragranceFamily.h"
#include "Review.h"
#include <string>
#include <vector>
#include <ostream>

class Fragrance
{
	unsigned fragranceId;
	static unsigned nextId;

	std::string name;
	std::string brand;

	double price = 0;
	double quantity;

	FragranceFamily note;
	std::vector<Review> reviews;

public:
	Fragrance(unsigned fragranceId, const std::string& name, const std::string& brand, double price,
			 FragranceFamily note, double quantity);

	Fragrance(const std::string& name, const std::string& brand, double price,
			  FragranceFamily note, double quantity);

	unsigned getFragranceId() const;
	const std::string& getName() const;
	const std::string& getBrand() const;
	double getPrice() const;
	double getQuantity() const;
	FragranceFamily getNote() const;
	const std::vector<Review>& getReviews() const;

	void addReview(const Review& review);
	void removeReview(unsigned reviewId);

	void addQuantity(double amount);
	void removeQuantity(double amount);

	double getRating() const;
	unsigned getReviewAuthorId(unsigned reviewId) const;

	static void setNextId(unsigned maxId);

	void save(std::ostream& out) const;

};
