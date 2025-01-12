#ifndef ATTEMPT_H_INCLUDED
#define ATTEMPT_H_INCLUDED

#include <string>
#include <vector>

class Attempt {
private:
    std::vector<int> digits;
    std::string* solution;

public:
    Attempt(std::vector<int> digits);
    std::vector<int> getDigits();
    virtual ~Attempt();
};

#endif // ATTEMPT_H_INCLUDED
