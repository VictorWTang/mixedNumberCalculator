#include <iostream>
#include <vector>
#include "parser.h"
#include "mixednumber.h"
#include "streamutilities.h"
#include "fraction.h"
#include "calculate.h"

using namespace std;

int main()
{
   string in = "83/4+987-402589(38-32)*12", print;
   vector<string> send;
   send = parser::parseToRPN(in);
   print = calculate::getAnswer(send);
   cout<<print<<endl;
   return 0;
}
