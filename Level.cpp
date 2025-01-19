#include "Level.h"

Level::Level(std::string type){
    if (type == "Łatwy") {
        this->type = LevelType::LOW;
        this->amountOfDigits = 4;
        this->setOfDigits = {"1", "2", "3", "4", "5"};

    } else if (type == "Średni") {
        this->type = LevelType::MEDIUM;
        this->amountOfDigits = 5;
        this->setOfDigits = {"1", "2", "3", "4", "5", "6"};
    } else {
        this->type = LevelType::HARD;
        this->amountOfDigits = 6;
        this->setOfDigits = {"1", "2", "3", "4", "5", "6", "7"};
    }
}

int Level::getAmountOfDigits(){
    return this->amountOfDigits;
}

std::string Level::getLevelTypeText(){
    if(this->type == LevelType::LOW){
        return "Łatwy";
    } else if (this->type == LevelType::MEDIUM){
        return "Średni";
    } else {
        return "Trudny";
    }
}

std::vector<std::string> Level::generateRandomNumber() {
    std::vector<std::string> randomNumber;

    // Check if setOfDigits is not empty
    if (setOfDigits.empty()) {
        return randomNumber; // Return an empty vector if no digits to choose from
    }

    // Seed the random number generator (do this only once in the program)
    std::srand(std::time(nullptr));

    // Generate `amountOfDigits` random numbers from `setOfDigits`
    for (int i = 0; i < amountOfDigits; ++i) {
        int randomIndex = std::rand() % setOfDigits.size(); // Pick a random index from setOfDigits
        randomNumber.push_back(setOfDigits[randomIndex]);   // Add the digit to the result vector
    }

    return randomNumber;
}
