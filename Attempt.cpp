#include "Attempt.h"

Attempt::Attempt(std::vector<int> digits){
    this->digits = digits;
}

std::vector<int> Attempt::getDigits() {
    return this->digits;
}

Attempt::~Attempt()
{
	delete this->solution;
}
