#include "parser.h"

std::vector<std::string> parser::strToVector(std::string input)
{
  std::vector<std::string> expVect;

  std::queue<char> line;
  std::string send;

  //put input into a queue
  for(int i = 0; i < input.size(); i ++)
    line.push(input[i]);

  char firstCheck = line.front();

  //in case first number is negative
  if(firstCheck == '-')
  {
    send += firstCheck;
    line.pop();
  }
  firstCheck = ' ';

  char check;
  //go through queue and add to expVect, string to vector
  do
  {
    check = line.front();
    if(isdigit(check) || check == '.' || check == ' ')
    {
      if(check == ' ')
      {
        send += check;
        line.pop();
        check = line.front();
        do
        {
          if(check != ' ')
            send += check;
          line.pop();
          check = line.front();
        }while(check != '/');
      }
      send += check;
      line.pop();
    }
    else
    {
      if(!send.empty())
      {
        expVect.push_back(send);
        send.clear();
      }
      send += check;
      expVect.push_back(send);
      send.clear();
      line.pop();
      char c;
      c = line.front();
      if(c == '-' || c == ' ')
        do
      {
        if(c == '-')
        {
          send += c;
          line.pop();
        }
        else
        {
          line.pop();
          c = line.front();
        }
      }while(c == ' ');
    }
  }while(!line.empty());

  if(!send.empty())
    expVect.push_back(send);

  return expVect;
}

std::string parser::toRPN(std::vector<std::string> exp)
{
  std::vector<std::string> RPNVect;

  std::stack<std::string> LIFO;
  std::queue<std::string> FIFO;

  char last;

  for(int i = 0; i < exp.size(); i++)
  {
    std::string check = exp[i];
    char next = check[0];

    if(isdigit(next) || (next == '-' && check.size() > 1))
    {
      FIFO.push(check);
    }
    else if(LIFO.empty() && !isdigit(next))
    {
      LIFO.push(check);
    }
    else if(check =="+" || check =="-" || check =="*" || check =="/")
    {
      int inStack, nextValue;
      inStack = getPrecedence(LIFO.top());
      nextValue = getPrecedence(check);
      if(inStack < nextValue)
        LIFO.push(check);
      else
      {
        do
        {
          FIFO.push(LIFO.top());
          LIFO.pop();
          if(!LIFO.empty())
            inStack = getPrecedence(LIFO.top());
        }while(inStack >= nextValue && !LIFO.empty());
        LIFO.push(check);
      }
    }
    else if(check == "(" || check == ")")
    {
      switch(next)
      {
      case '(':
        if(isdigit(last))
          LIFO.push("*");
        LIFO.push(check);
        break;
      case ')':
        do
        {
          FIFO.push(LIFO.top());
          LIFO.pop();

        }while(LIFO.top() != "(");
        if(LIFO.top() == "(")
        {
          LIFO.pop();
        }
        break;
      }
    }
    else
    {
      throw TRANSLATE_ERROR;
      std::cout<<check<<std::endl;
    }
    last = next;
  }
  if(!LIFO.empty())
  {
    do
    {
      FIFO.push(LIFO.top());
      LIFO.pop();
    }while(!LIFO.empty());
  }
  do{
    RPNVect.push_back(FIFO.front());
    FIFO.pop();

  }while(!FIFO.empty());

  //for the calculate call, should there be spaces between?
  std::string send;
  for(int i = 0; i < RPNVect.size(); i++)
  {
    send += RPNVect[i];
    send += " ";
  }
  return send;
}

int parser::getPrecedence(std::string str)
{
  char s = str[0];
  switch(s)
  {
  case '+':
    return 0;
    break;
  case '-':
    return 0;
    break;
  case '*':
    return 1;
    break;
  case '/':
    return 1;
    break;
  default:
    return -1;
  }
}

std::string parser::parseToRPN(const std::string  &input)
{
  std::string send;
  send = toRPN(strToVector(input));
  return send;
}

void parser::ensureInputValid(const std::string &input) {
  int leftParenCount = 0;
  int rightParenCount = 0;
  std::stringstream ss;
  ss << input;


  // Flags
  bool mixedNumberFound = false;
  bool operatorFound = false;
  bool leftParenFound = false;
  bool rightParenFound = false;

  mixedNumber trash;
  char nextChar;
  while(ss.good()) {
    nextChar = static_cast<char>(ss.get());
    std::cout << "Testing: " << nextChar << std::endl;

    if(nextChar == ' ') {
    } else if(streamUtilities::isNumber09(nextChar) ||
              (nextChar == '-' && streamUtilities::isNumber09(static_cast<char>(ss.peek())))) {
      ss.unget();
      try {
        ss >> trash;
      } catch (fraction::ERRORS e) {
        if(e == fraction::DIVIDE_BY_ZERO) {
          throw parseexception("Invalid number");
        }
      };

      if(rightParenFound) {
        throw parseexception("Number after right parenthesis"); // ie. (3 + 5) 44
      }

      mixedNumberFound = true;
      operatorFound = false;
      leftParenFound = false;

    } else if(streamUtilities::isOperator(nextChar)) {
      if(operatorFound || leftParenFound) {
        if(!(nextChar == '-' && streamUtilities::isNumber09(static_cast<char>(ss.peek())))) {
          if(leftParenFound) {
            throw parseexception("Operator after left parenthesis"); // ie. ( + 3) or (- 2 + 2)
          } else if(operatorFound) {
            throw parseexception("Operator after operator"); // ie. 5 + * or 3 / /
          }
        }
      }
      mixedNumberFound = false;
      operatorFound = true;
      leftParenFound = false;
      rightParenFound = false;

    } else if(nextChar == '(') {
      leftParenCount++;
      mixedNumberFound = false;
      operatorFound = false;
      leftParenFound = true;
      rightParenFound = false;

    } else if(nextChar == ')') {
      rightParenCount++;
      if(rightParenCount > leftParenCount) {
        throw parseexception("Unmatched right parenthesis"); // ie. 5 + 3 ) + 2
      }
      if(operatorFound) {
        throw parseexception("Right parenthesis after operator"); // ie. ( 5 + ) * 3
      }

      mixedNumberFound = false;
      leftParenFound = false;
      rightParenFound = true;
    } else {
      std::string error = "Invalid character: '";
      error += nextChar;
      error += '\'';
      throw parseexception(error);
    }
    ss.peek();
  }

  if(operatorFound) {
    throw parseexception("Dangling operator"); // ie. 5 +
  }

  if(leftParenCount != rightParenCount) {
    throw parseexception("Unmatched left parenthesis"); // ie. (( 5 + 3 ) + 2
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
