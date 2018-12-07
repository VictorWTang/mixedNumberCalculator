#ifndef PARSER_H
#define PARSER_H
#include <cstdlib>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include "streamutilities.h"
#include "parseexception.h"
#include "mixednumber.h"

class parser
{
public:
  enum ERRORS {TRANSLATE_ERROR};


  // Takes in algebraic expression, returns RPN expression
  // Throws parseexpression when invalid
//  static std::string parseToRPN(const std::string  &input);
  // Takes in algebraic expression, returns reformatted
  static std::string formatExpression(const std::string &input);

  static std::vector<std::string> parseToRPN(const std::string &input);

  // Temporary; for testing purposes
  // TODO: REMOVE AFTER TESTING
  static void ensureInputValid(const std::string &input);

private:
  //takes in expression and returns RPN
  static std::vector<std::string> toRPN(std::vector<std::string>);
  //used by RPN during equality comparisons
  static int getPrecedence(std::string);
  //product is sent to toRPN
  static std::vector<std::string> strToVector(std::string);

  // Determines if algebraic expression is valid
  // Throws INVALID_INPUT if input not valid
  //  static void ensureInputValid(const std::string &input);
  // Translates algebraic expression to RPN expression
  static std::string toRPN(const std::string &input);


  parser() {}
};

#endif // PARSER_H
