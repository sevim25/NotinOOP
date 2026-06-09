#include "Discount.h"

unsigned Discount::nextId = 1;

Discount::Discount(double discountPercent) 
	: discountId(nextId++), discountPercent(discountPercent) {}

Discount::Discount(unsigned discountId, double discountPercent)
	: discountId(discountId), discountPercent(discountPercent) {}

double Discount::apply(const Fragrance* fragrance) const
{
	return fragrance->getPrice() * (1 - (discountPercent / 100));
}

void Discount::setNextId(unsigned maxId)
{
	if (maxId >= nextId) {
		nextId = maxId + 1;
	}
}