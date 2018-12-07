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
#include <string>
#include "mixedNumber.h"

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
