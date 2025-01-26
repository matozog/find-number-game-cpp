#ifndef ATTEMPT_H_INCLUDED
#define ATTEMPT_H_INCLUDED

#include <string>
#include <vector>

class Attempt {
private:
    std::vector<std::string> digits;
    std::string* solution;
    int correctDigits = 0;
    int correctDigitsMisplaced = 0;

public:
    Attempt(const std::vector<std::string>& digits, std::vector<std::string> solution);
    const std::vector<std::string>& getDigits() const;
    const int getCorrectDigits() const;
    const int getCorrectDigitsMisplaced() const;
    ~Attempt();
};

#endif // ATTEMPT_H_INCLUDED
