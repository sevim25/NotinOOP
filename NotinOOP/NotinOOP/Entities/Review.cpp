#include "Review.h"
#include <stdexcept>
#include <iostream>

unsigned Review::nextReviewId = 1;

Review::Review(const std::string& fragranceName, unsigned userId, const std::string& comment, unsigned rating)
    : reviewId(nextReviewId++), fragranceName(fragranceName), userId(userId)
{
    setComment(comment);
    setRating(rating);
}

Review::Review(unsigned reviewId, const std::string& fragranceName, unsigned userId, const std::string& comment, unsigned rating)
    : reviewId(reviewId), fragranceName(fragranceName), userId(userId)
{
    setComment(comment);
    setRating(rating);
}

void Review::setComment(const std::string& comment)
{
    if (comment.size() > MAX_LEN) {
        throw std::invalid_argument("Review comment is too long");
    }
    this->comment = comment;
}

void Review::setRating(unsigned rating)
{
    if (rating > MAX_RATING) {
        throw std::invalid_argument("Rating must be between 0 and 5");
    }

    this->rating = rating;
}

unsigned Review::getReviewId() const
{
    return reviewId;
}

const std::string& Review::getFragranceName() const
{
    return fragranceName;
}

unsigned Review::getUserId() const
{
    return userId;
}

const std::string& Review::getComment() const
{
    return comment;
}

unsigned Review::getRating() const
{
    return rating;
}

void Review::setNextId(unsigned maxId)
{
    if (maxId >= nextReviewId) {
        nextReviewId = maxId + 1;
    }
}

void Review::save(std::ostream& out) const
{
    std::string safeComment = comment;

    for (char& c : safeComment) {
        if (c == ' ') {
            c = '_';
        }
    }

    out << reviewId << " " << userId << " " << rating << " " << safeComment;
}