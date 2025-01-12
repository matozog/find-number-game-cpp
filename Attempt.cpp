#include "Attempt.h"

Attempt::Attempt(const std::vector<std::string>& digits) : digits(digits), solution(nullptr) {
    // Optionally initialize solution if needed
}

const std::vector<std::string>& Attempt::getDigits() const {
    return this->digits;
}

Attempt::~Attempt() {
    if (solution) {
        delete solution;
    }
}
