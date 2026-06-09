#pragma once
#include <string>
#include "Discount.h"

class BrandDiscount : public Discount
{
	std::string brandName;

public:
	BrandDiscount(double discountPercent, const std::string& brandName);
	BrandDiscount(unsigned discountId, double discountPercent, const std::string& brandName);

	double apply(const Fragrance* fragrance) const override;
};