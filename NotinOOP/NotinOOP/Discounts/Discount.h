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

	virtual double apply(const Fragrance* fragrance) const;

	static void setNextId(unsigned maxId);
	virtual ~Discount() = default;
};