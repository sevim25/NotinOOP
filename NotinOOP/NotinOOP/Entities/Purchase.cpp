#include "Purchase.h"
#include <stdexcept>
#include <iostream>

unsigned Purchase::nextPurchaseId = 1;

Purchase::Purchase(unsigned userId, const std::vector<std::string>& boughtFragranceNames, PurchaseStatus status, double totalPrice)
    : purchaseId(nextPurchaseId++), userId(userId), boughtFragranceNames(boughtFragranceNames), status(status)
{
    setPrice(totalPrice);
}

Purchase::Purchase(unsigned purchaseId, unsigned userId, const std::vector<std::string>& boughtFragranceNames, PurchaseStatus status, double totalPrice)
: purchaseId(purchaseId), userId(userId), boughtFragranceNames(boughtFragranceNames), status(status)
{
    setPrice(totalPrice);
}

unsigned Purchase::getPurchaseId() const
{
    return purchaseId;
}

unsigned Purchase::getUserId() const
{
    return userId;
}

PurchaseStatus Purchase::getStatus() const
{
    return status;
}

double Purchase::getTotalPrice() const
{
    return totalPrice;
}

const std::vector<std::string>& Purchase::getBoughtFragranceNames() const
{
    return boughtFragranceNames;
}

void Purchase::setPrice(double price)
{
    if (price < 0) {
        throw std::invalid_argument("Total price cannot be negative");
    }

    totalPrice = price;
}

void Purchase::setStatus(PurchaseStatus status)
{
    this->status = status;
}

void Purchase::setNextId(unsigned maxId)
{
    if (maxId >= nextPurchaseId) {
        nextPurchaseId = maxId + 1;
    }
}

void Purchase::show() const
{
    std::cout << "--- Purchase ID: " << purchaseId << " ---\n";
    std::cout << "User ID: " << userId << "\n";

    std::cout << "Status: ";
    switch (status) {
    case PurchaseStatus::PENDING: std::cout << "PENDING\n"; break;
    case PurchaseStatus::DELIVERED: std::cout << "DELIVERED\n"; break;
    case PurchaseStatus::CANCELED: std::cout << "CANCELED\n"; break;
    }

    std::cout << "Fragrances:\n";
    for (const auto& name : boughtFragranceNames) {
        std::cout << "  - " << name << "\n";
    }

    std::cout << "Total Price: " << totalPrice << "\n";
    std::cout << "------------------------\n";
}

void Purchase::showAllSuccessfulPurchases() const
{
    if (this->status == PurchaseStatus::DELIVERED)
    {
        std::cout << "--- Purchase ID: " << purchaseId << " ---\n";
        std::cout << "User ID: " << userId << "\n";
        std::cout << "Status: DELIVERED\n";

        std::cout << "Fragrances:\n";
        for (const auto& name : boughtFragranceNames) {
            std::cout << "  - " << name << "\n";
        }

        std::cout << "Total Price: " << totalPrice << "\n";
        std::cout << "------------------------\n";
    }
}