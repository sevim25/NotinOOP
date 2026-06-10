#pragma once
#include "Entities/Fragrance.h"

class Discount 
{
protected:
	unsigned discountId;
	static unsigned nextId;

	double discountPercent;


public:
	Discount(double discountPercent);
	Discount(unsigned discountId, double discountPercent);

	double getDiscountPercent() const;

	virtual double apply(const Fragrance* fragrance) const;
	virtual void save(std::ostream& out) const;

	static void setNextId(unsigned maxId);
	virtual ~Discount() = default;
};