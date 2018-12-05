#include "parser.h"

std::string parser::parseToRPN(const std::string  &input) {

}

std::string parser::formatExpression(const std::string &input) {

}

void parser::ensureInputValid(const std::string &input) {
  int leftParenCount = 0;
  int rightParenCount = 0;
  std::stringstream ss;
  ss << input;


  // Flags
  bool fractionFound;
  bool intFound;
  bool doubleFound;
  bool operatorFound;
  bool leftParenFound;
  bool rightParenFound;
  bool spaceFound;




  char nextChar;
  while(ss.good()) {
    nextChar = static_cast<char>(ss.peek());
    if(isNumber(nextChar)) {

    } else if(isOperator(nextChar)) {

    } else if(nextChar == '(') {
      leftParenCount++;
    } else if(nextChar == ')') {
      rightParenCount++;
      if(operatorFound) {
        throw INVALID_INPUT;
      }
      if(rightParenCount > leftParenCount) {
        throw INVALID_INPUT;
      }
    } else if(nextChar )
  }

}




std::string parser::toRPN(const std::string &input) {

}
