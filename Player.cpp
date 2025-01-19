#include "Player.h"

Player::Player(std::string nickname){
    this->nickname = nickname;
}

std::vector<Attempt> Player::getAttempts(){
    return this->attempts;
}

void Player::addAttempt(Attempt attempt) {
    this->attempts.push_back(attempt);
}

std::string Player::getNickname(){
    return this->nickname;
}
