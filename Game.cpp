#include "Game.h"
#include <algorithm>
#include <wx/msgdlg.h>
#include <iostream>
#include <vector>
#include <fstream>

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

void Game::savePlayerStats(){
    bool rewriteRanking = false;
    auto currentStats = std::find_if(playersStats.begin(), playersStats.end(), [this](const PlayerStats& p) {
        return p.getNick() == player1->getNickname() && p.getLevel() == level->getLevelTypeText();
    });

    if (currentStats != playersStats.end()) {
        if(areNewPlayerStatsBetter(currentStats)){
            currentStats->setTime(this->player1->getChallengeTime());
            currentStats->setAmountOfAttempts(this->player1->getAttempts().size());
            rewriteRanking = true;
        }
    } else {
        PlayerStats newStat(this->player1->getNickname(), this->level->getLevelTypeText(), this->player1->getAttempts().size(), this->player1->getChallengeTime());
        this->playersStats.emplace_back(newStat);
        rewriteRanking = true;
    }

    if(rewriteRanking){
        savePlayersStatsToCSVFile();
        wxMessageBox("Rewrite ranking", _("Bląd wczytywania"), wxOK | wxICON_ERROR);
    }
}

bool Game::areNewPlayerStatsBetter(auto& currentStats) {
    if(this->player1->getAttempts().size() < currentStats->getAttempts()){
        return true;
    } else if (this->player1->getAttempts().size() == currentStats->getAttempts()) {
        return this->player1->getChallengeTime() < currentStats->getTime();
    }

    return false;
}

void Game::savePlayersStatsToCSVFile(){
    std::ofstream file("ranking.csv");

    // Check if the file opened successfully
    if (!file.is_open()) {
        wxMessageBox("Błąd otwierania pliku ranking csv", _("Bląd wczytywania"), wxOK | wxICON_ERROR);
        return;
    }

    // Write player stats
    for (const auto& player : playersStats) {
        file << player.getNick() << ","
             << player.getLevel() << ","
             << player.getAttempts() << ","
             << player.getTime() << "\n";
    }

    file.close();  // Close file
}
