#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Attempt.h"
#include <string>

class Player {
    private:
        std::string nickname;
        std::vector<Attempt> attempts;
        double challengeTime = 0.0;

    public:
        Player(std::string nickname);
        std::vector<Attempt> getAttempts();
        void addAttempt(Attempt attempt);
        std::string getNickname();
        void setChallengeTime(double challengeTime);
        double getChallengeTime() const { return challengeTime; }
};

#endif // PLAYER_H_INCLUDED
