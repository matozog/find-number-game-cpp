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

bool Game::checkGuess(const std::vector<std::string>& guess) {
    if (guess.size() != solution.size()) {
        return false; // If sizes differ, the vectors are not equal
    }

    for (size_t i = 0; i < guess.size(); ++i) {
        if (guess[i] != solution[i]) {
            return false; // Return false immediately if any element differs
        }
    }

    return true;
}

void Game::setSolution(const std::vector<std::string>& solution) {
    this->solution = solution;
}

std::vector<std::string> Game::getSolution() const {
    return solution;
}
