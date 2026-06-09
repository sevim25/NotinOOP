#pragma once
#include "Discount.h"

class BonusDiscount : public Discount
{
	double bonus;

public:
	BonusDiscount(double discountPercent, double bonus);
	BonusDiscount(unsigned discountId, double discountPercent, double bonus);

	double apply(const Fragrance* fragrance) const override;
};