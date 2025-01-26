#include "Attempt.h"
#include <unordered_map>

Attempt::Attempt(const std::vector<std::string>& digits, std::vector<std::string> solution) : digits(digits), solution(nullptr) {
    std::unordered_map<std::string, int> solutionDigitsFrequency;

    for (const auto& digit : solution) {
        solutionDigitsFrequency[digit]++;
    }

    for (size_t i = 0; i < solution.size(); ++i) {
        if (digits[i] == solution[i]) {
            this->correctDigits++;
            solutionDigitsFrequency[digits[i]]--;
        } else if(solutionDigitsFrequency[digits[i]] > 0) {
            this->correctDigitsMisplaced++;
            solutionDigitsFrequency[digits[i]]--;
        }
    }
}

const std::vector<std::string>& Attempt::getDigits() const {
    return this->digits;
}

const int Attempt::getCorrectDigits() const {
    return this->correctDigits;
}

const int Attempt::getCorrectDigitsMisplaced() const {
    return this->correctDigitsMisplaced;
}

Attempt::~Attempt() {
    if (solution) {
        delete solution;
    }
}
