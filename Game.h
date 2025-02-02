#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Level.h"
#include "Player.h"
#include "PlayerStats.h"
#include <string>

class Game{
private:
    Level *level;
    std::string type;
    std::vector<std::string> solution; // Liczba wygenerowana przez komputer
    Player* player1;
    Player* player2;
    std::vector<PlayerStats>& playersStats;

    bool areNewPlayerStatsBetter(auto& currentStats);
    void savePlayersStatsToCSVFile();

public:
    Game(Level* level, Player* player1, std::vector<PlayerStats>& playersStats): level(level), player1(player1), playersStats(playersStats) {};
    Level* getLevel();
    Player* getPlayer1();
    Player* getPlayer2();

    void setSolution(const std::vector<std::string>& solution);
    std::vector<std::string> getSolution() const;
    bool checkGuess(const std::vector<std::string>& guess);
    void savePlayerStats();
    std::vector<PlayerStats> getPlayerStats() { return this->playersStats; }
};

#endif // GAME_H_INCLUDED
