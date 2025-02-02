#ifndef PLAYERSTATS_H_INCLUDED
#define PLAYERSTATS_H_INCLUDED

#include <string>
#include "Level.h"

class PlayerStats {
private:
    std::string playerNick;
    int amountOfAttempts;
    double time;
    std::string level;

public:
    // Constructor
    PlayerStats(const std::string& nick, const std::string& lvl, int attempts, double t)
        : playerNick(nick), amountOfAttempts(attempts), time(t), level(lvl) {}

    // Getters for accessing private members
    const std::string& getNick() const { return playerNick; }
    const std::string& getLevel() const { return level; }
    int getAttempts() const { return amountOfAttempts; }
    double getTime() const { return time; }
    void setTime(double time) { this->time = time; }
    void setAmountOfAttempts(int amountOfAttempts) { this->amountOfAttempts = amountOfAttempts; }
};


#endif // PLAYERSTATS_H_INCLUDED
