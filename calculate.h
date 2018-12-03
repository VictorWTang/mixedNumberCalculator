#ifndef CALCULATE_H
#define CALCULATE_H
#include <string>
#include "mixedNumber.h"

class calculate
{
public:
  mixedNumber calculateExpression(const std::string &rpnExpression);
private:
  calculate() {}
};

#endif // CALCULATE_H
