#include "BonusDiscount.h"

BonusDiscount::BonusDiscount(double discountPercent, double bonus)
    : Discount(discountPercent), bonus(bonus) {}

BonusDiscount::BonusDiscount(unsigned discountId, double discountPercent, double bonus)
    : Discount(discountId, discountPercent), bonus(bonus) {}

double BonusDiscount::apply(const Fragrance* fragrance) const
{
    double finalPrice = Discount::apply(fragrance) - bonus;

    if (finalPrice < 0) {
        return 0;
    }

    return finalPrice;
}

void BonusDiscount::save(std::ostream& out) const
{
    out << "BONUS " << getDiscountPercent() << " " << bonus;
}
