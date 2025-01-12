#ifndef ATTEMPT_H_INCLUDED
#define ATTEMPT_H_INCLUDED

#include <string>
#include <vector>

class Attempt {
private:
    std::vector<std::string> digits;
    std::string* solution;

public:
    Attempt(const std::vector<std::string>& digits);
    const std::vector<std::string>& getDigits() const;
    ~Attempt();
};

#endif // ATTEMPT_H_INCLUDED
