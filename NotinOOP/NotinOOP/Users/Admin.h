#pragma once
#include <memory>
#include "User.h"
#include "Entities/Purchase.h"

class Admin : public User
{
private:
	std::vector<std::unique_ptr<Fragrance>>& fragrances;
	std::vector<std::unique_ptr<User>>& users;
	std::vector<Purchase>& purchases;

public:
	Admin(unsigned userId, const std::string& username, const std::string& password, 
		  std::vector<std::unique_ptr<Fragrance>>& fragrances,
		  std::vector<std::unique_ptr<User>>& users, 
		  std::vector<Purchase>& purchases);

	virtual Admin* asAdmin() override;

	void blockUser(const std::string& username);

	void createFragrance(const std::string& fragranceName, const std::string& brand,
						double price, FragranceFamily note, double quantity);

	void addQuantity(const std::string& fragranceName, double quantity);
	void deliver(unsigned purchaseId);
	void removeReview(unsigned fragranceId, unsigned reviewId);

	void help() const override;
	std::string getRole() const override;

	void save(std::ostream& out) const override;
};