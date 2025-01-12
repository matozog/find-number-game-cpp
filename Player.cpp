#include "Player.h"

Player::Player(std::string nickname){
    this->nickname = nickname;
}

std::vector<Attempt> Player::getAttempts(){
    return this->attempts;
}
