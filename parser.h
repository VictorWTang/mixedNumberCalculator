#ifndef PARSER_H
#define PARSER_H
#include <cstdlib>
#include <string>
#include <sstream>

class parser
{
public:
  enum ERRORS {INVALID_INPUT};

  // Takes in algebraic expression, returns RPN expression
  // Throws INVALID_INPUT if input not valid
  static std::string parseToRPN(const std::string  &input);

  // Takes in algebraic expression, returns reformatted
  static std::string formatExpression(const std::string &input);

private:
  // Determines if algebraic expression is valid
  // Throws INVALID_INPUT if input not valid
  static void ensureInputValid(const std::string &input);
  // Translates algebraic expression to RPN expression
  static std::string toRPN(const std::string &input);
  parser() {}
};

#endif // PARSER_H
