#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Attempt.h"
#include <string>

class Player {
    private:
        std::string nickname;
        std::vector<Attempt> attempts;

    public:
        Player(std::string nickname);
        std::vector<Attempt> getAttempts();
        void addAttempt(Attempt attempt);
};

#endif // PLAYER_H_INCLUDED
