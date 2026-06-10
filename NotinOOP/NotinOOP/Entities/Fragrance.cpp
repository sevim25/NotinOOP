#include "Fragrance.h"
#include <stdexcept>

unsigned Fragrance::nextId = 1;

Fragrance::Fragrance(unsigned fragranceId, const std::string& name, const std::string& brand, double price, FragranceFamily note, double quantity)
    : fragranceId(fragranceId), name(name), brand(brand), price(price), note(note), quantity(quantity)
{
}

Fragrance::Fragrance(const std::string& name, const std::string& brand, double price, FragranceFamily note, double quantity)
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

double Fragrance::getQuantity() const
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

void Fragrance::addQuantity(double amount)
{
    quantity += amount;
}

void Fragrance::removeQuantity(double amount)
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

unsigned Fragrance::getReviewAuthorId(unsigned reviewId) const
{
    for (const auto& review : reviews) {
        if (review.getReviewId() == reviewId) {
            return review.getUserId();
        }
    }

    throw std::invalid_argument("Error: Review with this ID does not exist in the fragrance.");
}

void Fragrance::setNextId(unsigned maxId)
{
    if (maxId >= nextId) {
        nextId = maxId + 1;
    }
}

void Fragrance::save(std::ostream& out) const {
    out << fragranceId << " " << name << " " << brand << " " << price << " "
        << toString(note) << " " << quantity << " " << reviews.size() << "\n";

    for (const auto& r : reviews) {
        r.save(out);  
        out << "\n";
    }
}