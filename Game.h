#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Level.h"
#include "Player.h"
#include <string>

class Game{
private:
    Level *level;
    std::string type;
    std::vector<std::string> solution; // Liczba wygenerowana przez komputer
    Player* player1;
    Player* player2;

public:
    Game(Level* level, const std::string& type, Player* player1);
    Game(Level* level, const std::string& type, Player* player1, Player* player2);
    Level* getLevel();
    Player* getPlayer1();
    Player* getPlayer2();

    void setSolution(const std::vector<std::string>& solution);
    std::vector<std::string> getSolution() const;
    bool checkGuess(const std::vector<std::string>& guess);
};

#endif // GAME_H_INCLUDED
