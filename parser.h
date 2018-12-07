#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

#ifndef PARSER_H
#define PARSER_H

class parser
{
public:

    enum ERRORS {INVALID_INPUT, TRANSLATE_ERROR};

  parser();
  parser(std::string input);
  ~parser();

  // Takes in algebraic expression, returns reformatted
  static std::string formatExpression(const std::string &input);

  static std::vector<std::string> parseToRPN(const std::string &input);

private:

  //takes in expression and returns RPN
  static std::vector<std::string> toRPN(std::vector<std::string>);
  //used by RPN during equality comparisons
  static int getPrecedence(std::string);
  //product is sent to toRPN
  static std::vector<std::string> strToVector(std::string);

  // Determines if algebraic expression is valid
  // Throws INVALID_INPUT if input not valid
  static void ensureInputValid(const std::string &input);
  // Translates algebraic expression to RPN expression
};

#endif // PARSER_H
