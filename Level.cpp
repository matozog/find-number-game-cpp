#include "Level.h"

Level::Level(std::string type){
    if (type == "Łatwy") {
        this->type = LevelType::LOW;
        this->amountOfDigits = 4;
        this->setOfDigits = {1, 2, 3, 4, 5};

    } else if (type == "Średni") {
        this->type = LevelType::MEDIUM;
        this->amountOfDigits = 5;
        this->setOfDigits = {1, 2, 3, 4, 5, 6};
    } else {
        this->type = LevelType::HARD;
        this->amountOfDigits = 6;
        this->setOfDigits = {1, 2, 3, 4, 5, 6, 7};
    }
}

int Level::getAmountOfDigits(){
    return this->amountOfDigits;
}
