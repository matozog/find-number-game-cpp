#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include<string>
#include<vector>

enum LevelType{
    LOW,
    MEDIUM,
    HARD
};

class Level{
private:
    LevelType type;
    int amountOfDigits;
    std::vector<int> setOfDigits;

public:
    Level(const std::string type);
    int getAmountOfDigits();
};

#endif // LEVEL_H_INCLUDED
