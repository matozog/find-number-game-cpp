#include "Game.h"

Game::Game(Level* level, const std::string& type, Player* player1){
    this->level = level;
    this->type = type;
    this->player1 = player1;
}

Game::Game(Level* level, const std::string& type, Player* player1, Player* player2){
    this->level = level;
    this->type = type;
    this->player1 = player1;
    this->player2 = player2;
}

Level* Game::getLevel() {
    return this->level;
}

Player* Game::getPlayer1(){
    return this->player1;
}

Player* Game::getPlayer2(){
    return this->player2;
}
