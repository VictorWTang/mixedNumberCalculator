#ifndef PARSER_H
#define PARSER_H
#include <cstdlib>
#include <string>

class parser
{
public:
  enum ERRORS {INVALID_INPUT};

  // Takes in algebraic expression, returns RPN expression
  static std::string parseExpression(const std::string &input);

private:
  // Determines if algebraic expression is valid
  static bool isInputValid(const std::string &input);
  // Translates algebraic expression to RPN expression
  static std::string translateExpression(const std::string &input);
  parser();
};

#endif // PARSER_H
