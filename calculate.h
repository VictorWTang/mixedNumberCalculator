#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <sstream>
#include "mixednumber.h"
#include "parser.h"

#ifndef CALCULATE_H
#define CALCULATE_H


class calculate
{
public:
    calculate();
    ~calculate();
    static std::string getAnswer(std::vector<std::string>);

private:
    static std::string doCalculations(std::vector<std::string>);
};

#endif // CALCULATE_H
