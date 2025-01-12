#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Level.h"
#include "Player.h"
#include <string>

class Game{
private:
    Level *level;
    std::string type;
    Player* player1;
    Player* player2;

public:
    Game(Level* level, const std::string& type, Player* player1);
    Game(Level* level, const std::string& type, Player* player1, Player* player2);
    Level* getLevel();
    Player* getPlayer1();
    Player* getPlayer2();
};

#endif // GAME_H_INCLUDED
