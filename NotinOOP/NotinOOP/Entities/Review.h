#pragma once
#include <string>

class Review
{
	unsigned reviewId;
	static unsigned nextReviewId;

	unsigned userId;
	std::string fragranceName;
	std::string comment;
	unsigned rating;

	static constexpr unsigned MAX_LEN = 1000;
	static constexpr unsigned MAX_RATING = 5;

public:
	Review(const std::string& fragranceName, unsigned userId, const std::string& comment, unsigned rating);
	Review(unsigned reviewId, const std::string& fragranceName, unsigned userId, const std::string& comment, unsigned rating);

	void setComment(const std::string& comment);
	void setRating(unsigned rating);

	unsigned getReviewId() const;
	const std::string& getFragranceName() const;
	unsigned getUserId() const;
	const std::string& getComment() const;
	unsigned getRating() const;

	static void setNextId(unsigned maxId);
};
