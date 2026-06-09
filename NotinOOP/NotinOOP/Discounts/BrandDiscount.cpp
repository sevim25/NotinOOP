#include "BrandDiscount.h"

BrandDiscount::BrandDiscount(double discountPercent, const std::string& brandName)
    : Discount(discountPercent), brandName(brandName) {}

BrandDiscount::BrandDiscount(unsigned discountId, double discountPercent, const std::string& brandName)
    : Discount(discountId, discountPercent), brandName(brandName) {}

double BrandDiscount::apply(const Fragrance* fragrance) const
{
    if (fragrance->getBrand() == brandName)
    {
        return Discount::apply(fragrance);
    }
    return fragrance->getPrice();
}
