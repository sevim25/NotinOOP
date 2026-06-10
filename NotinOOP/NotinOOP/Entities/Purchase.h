#pragma once
#include <vector>
#include <string>
#include "Fragrance.h"
#include <ostream>

enum class PurchaseStatus {
	PENDING, DELIVERED, CANCELED
};

class Purchase
{
	unsigned purchaseId;
	static unsigned nextPurchaseId;

	unsigned userId;

	PurchaseStatus status = PurchaseStatus::PENDING;
	std::vector<std::string> boughtFragranceNames;

	double totalPrice;

public:
	Purchase(unsigned userId, const std::vector<std::string>& boughtFragranceNames, PurchaseStatus status, double totalPrice);
	Purchase(unsigned purchaseId, unsigned userId, const std::vector<std::string>& boughtFragranceNames, PurchaseStatus status, double totalPrice);

	unsigned getPurchaseId() const;
	unsigned getUserId() const;
	PurchaseStatus getStatus() const;
	double getTotalPrice() const;

	const std::vector<std::string>& getBoughtFragranceNames() const;

	void setPrice(double price);
	void setStatus(PurchaseStatus status);

	void show() const;

	static void setNextId(unsigned maxId);

	void save(std::ostream& out) const;
};
