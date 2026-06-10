#pragma once
#include "Command.h"
#include <string>
#include "Entities/FragranceFamily.h"
#include "Entities/Fragrance.h"
class NotinOOP;

class CreateFragranceCommand : public Command
{
    NotinOOP& system;
    std::string name;
    std::string brand;
    double price;
    double quantity;
    FragranceFamily note;

public:
    CreateFragranceCommand(NotinOOP& system, const std::string& name, const std::string& brand,
                             double price, FragranceFamily note, double quantity);

    void execute() override;

};