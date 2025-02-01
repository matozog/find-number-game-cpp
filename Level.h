#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include<string>
#include<vector>
#include <cstdlib>  // For std::rand and std::srand
#include <ctime>

enum LevelType{
    LOW,
    MEDIUM,
    HARD
};

class Level{
private:
    LevelType type;
    int amountOfDigits;
    std::vector<std::string> setOfDigits;

public:
    Level(const std::string type);
    int getAmountOfDigits();
    LevelType getLevelType();
    std::string getLevelTypeText();
    std::vector<std::string> generateRandomNumber(); // Nowa metoda
};

#endif // LEVEL_H_INCLUDED
