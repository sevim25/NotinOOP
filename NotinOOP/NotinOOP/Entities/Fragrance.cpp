#include "Fragrance.h"

unsigned Fragrance::nextId = 1;

Fragrance::Fragrance(unsigned fragranceId, const std::string& name, const std::string& brand, double price, FragranceFamily note, size_t quantity)
    : fragranceId(fragranceId), name(name), brand(brand), price(price), note(note), quantity(quantity)
{
}

Fragrance::Fragrance(const std::string& name, const std::string& brand, double price, FragranceFamily note, size_t quantity)
    : fragranceId(nextId++), name(name), brand(brand), price(price), note(note), quantity(quantity) {
}

unsigned Fragrance::getFragranceId() const
{
    return fragranceId;
}

const std::string& Fragrance::getName() const
{
    return name;
}

const std::string& Fragrance::getBrand() const
{
    return brand;
}

double Fragrance::getPrice() const
{
    return price;
}

size_t Fragrance::getQuantity() const
{
    return quantity;
}

FragranceFamily Fragrance::getNote() const
{
    return note;
}

const std::vector<Review>& Fragrance::getReviews() const
{
    return reviews;
}

void Fragrance::addReview(const Review& review)
{
    reviews.push_back(review);
}

void Fragrance::removeReview(unsigned reviewId)
{
    for (auto it = reviews.begin(); it != reviews.end(); ++it) {
        if ((it)->getReviewId() == reviewId) {
            reviews.erase(it);
            return;
        }
    }
}

void Fragrance::addQuantity(size_t amount)
{
    quantity += amount;
}

void Fragrance::removeQuantity(size_t amount)
{
    if (quantity >= amount) {
        quantity -= amount;
    }
}

double Fragrance::getRating() const
{
    if (reviews.empty()) {
        return 0.0;
    }

    double sum = 0;

    for (const auto& r : reviews) {
        sum += r.getRating();
    }

    return sum / reviews.size();
}

void Fragrance::setNextId(unsigned maxId)
{
    if (maxId >= nextId) {
        nextId = maxId + 1;
    }
}