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

class parser
{
public:
  enum ERRORS {
    INVALID_INPUT,
    INVALID_NUMBER,
    NUMBER_AFTER_RIGHT_PARENTHESIS,
    NEGATIVE_AFTER_RIGHT_PARENTHESIS,
    OPERATOR_AFTER_LEFT_PARENTHESIS,
    OPERATOR_AFTER_OPERATOR,
    DECIMAL_WITHOUT_PROCEEDING_NUMBER,
    DECIMAL_WITHOUT_PRECEEDING_NUMBER,
    INVALID_CHARACTER,
    TRANSLATE_ERROR
  };

  // Takes in algebraic expression, returns RPN expression
  // Throws INVALID_INPUT if input not valid
  static std::string parseToRPN(const std::string  &input);

  // Takes in algebraic expression, returns reformatted
  static std::string formatExpression(const std::string &input);

private:
  static std::string toRPN(std::vector<std::string>);
  static std::vector<std::string> strToVector(std::string);
  static int getPrecedence(std::string);

  // Determines if algebraic expression is valid
  // Throws INVALID_INPUT if input not valid
  static void ensureInputValid(const std::string &input);
  // Translates algebraic expression to RPN expression
  static std::string toRPN(const std::string &input);
  parser() {}
};

#endif // PARSER_H
