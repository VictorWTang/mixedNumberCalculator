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
  bool fractionFound = false;
  bool intFound = false;
  bool decimalFound = false;
  bool operatorFound = false;
  bool leftParenFound = false;
  bool rightParenFound = false;
  bool negateFound = false;
  bool spaceFound = false;


  char nextChar;
  while(ss.good()) {
    nextChar = static_cast<char>(ss.get());

    if(nextChar == ' ') {
      intFound = false;
    } else if(streamUtilities::isNumber09(nextChar)) {
      if(nextChar == '0' && ss.peek() != '.') {
        if(!intFound) {
          throw INVALID_NUMBER; // Invalid number, ie. 023 or 0/3
        }
      } else if(rightParenFound) {
        throw NUMBER_AFTER_RIGHT_PARENTHESIS; // Number after right parentheses, ie. (3 + 5) 44
      } else {
        intFound = true;
        leftParenFound = false;
      }
    } else if(nextChar == '-' && streamUtilities::isNumber09(static_cast<char>(ss.peek()))) {
      if(rightParenFound) {
        throw NEGATIVE_AFTER_RIGHT_PARENTHESIS; // Negative sign after right parentheses, ie. (3 + 5) -44
      }
      negateFound = true;
    } else if(streamUtilities::isOperator(nextChar)) {
      if(operatorFound || leftParenFound) {
        if(nextChar != '-' && !streamUtilities::isNumber09(static_cast<char>(ss.peek()))) {
          if(leftParenFound) {
            throw OPERATOR_AFTER_LEFT_PARENTHESIS; // Operator after left parenthese, ie. ( + 3) or (- 2 + 2)
          } else {
            throw OPERATOR_AFTER_OPERATOR; // Operator after operator, but not negate sign, ie. + - or / /
          }
        }
      }
      if(nextChar == '-') {
        if(streamUtilities::isNumber09(static_cast<char>(ss.peek()))) {

        } else {

        }
      } else if(nextChar == '/') {

      }
    } else if(nextChar == '(') {
      if(decimalFound) {
        throw INVALID_INPUT; // Decimal
      }
      leftParenCount++;
      leftParenFound = true;

    } else if(nextChar == ')') {

    } else if (nextChar == '.') {
      if(intFound) {
        if(!streamUtilities::isNumber09(static_cast<char>(ss.peek()))) {
          throw DECIMAL_WITHOUT_PROCEEDING_NUMBER; // Decimal without proceeding number, ie. 3. or 123.
        }
        decimalFound = true;
        intFound = false;
      } else {
        throw DECIMAL_WITHOUT_PRECEEDING_NUMBER; // ie. -.3 or + .(5 + 3)
      }
    } else {
      throw INVALID_CHARACTER;
    }



  }


//  char nextChar;
//  while(ss.good()) {
//    nextChar = static_cast<char>(ss.peek());
//    if(isNumber(nextChar)) {

//    } else if(isOperator(nextChar)) {

//    } else if(nextChar == '(') {
//      leftParenCount++; // TODO Can a left bracket come after a number?
//    } else if(nextChar == ')') {
//      rightParenCount++;
//      if(operatorFound) {
//        throw INVALID_INPUT;
//      }
//      if(rightParenCount > leftParenCount) {
//        throw INVALID_INPUT;
//      }
//    } else if(nextChar )
//  }
}




std::string parser::toRPN(const std::string &input) {

}
