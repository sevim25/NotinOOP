#pragma once
#include "Command.h"
#include "System/NotinOOP.h"
#include <string>

class RemoveReviewCommand : public Command
{
	NotinOOP& system;
	unsigned fragranceId;
	unsigned reviewId;

public:
	RemoveReviewCommand(NotinOOP& system, unsigned fragranceId, unsigned reviewId);

	void execute() override;
};