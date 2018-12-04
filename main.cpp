#include <iostream>
#include "mixednumber.h"

using namespace std;

void runTests();
void testFraction(string input, string expectedOutput);
string passFail(string output, string expectedOutput);

int main()
{
  runTests();
  return 0;
}

void runTests() {
  // FRACTION TESTS
  testFraction("5", "5");
  testFraction("5/3", "5/3");
  testFraction("23/1", "23");
  testFraction("6/3", "2");
  testFraction("30/20", "3/2");
  testFraction("5.1", "51/10");
  testFraction("5.123", "5123/1000");
  testFraction("-5", "-5");
  testFraction("-5/1", "-5");
  testFraction("-1/2", "-1/2");
  testFraction("-0.5", "-1/2");



}

void testFraction(string input, string expectedOutput) {
  stringstream ss;
  fraction frac;
  string output;
  ss << input;
  ss >> frac;
  ss << frac;
  getline(ss, output);
  cout << "          INPUT: " << setw(10) << input << endl;
  cout << "         OUTPUT: " << setw(10) << output << endl;
  cout << "EXPECTED OUTPUT: " << setw(10) << expectedOutput << " " << passFail(output, expectedOutput) << endl;
  cout << endl;
}

string passFail(string output, string expectedOutput) {
  if(output == expectedOutput) {
    return "PASS";
  }
  return "FAIL";
}
