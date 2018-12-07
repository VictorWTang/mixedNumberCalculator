#ifndef CALCULATE_H
#define CALCULATE_H
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include "mixednumber.h"


class calculate
{
public:
  static std::string getAnswer(std::vector<std::string>);

//  mixedNumber calculateExpression(const std::string &rpnExpression);
private:
  static std::string doCalculations(std::vector<std::string>);


  calculate() {}
};

#endif // CALCULATE_H
