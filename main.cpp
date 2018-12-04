#include <iostream>
#include "mixednumber.h"

using namespace std;

void runTests();

template <class T>
void testTypeInput(string input, string expectedOutput);
string passFail(string output, string expectedOutput);

int main()
{
  runTests();
  return 0;
}

void runTests() {
  // FRACTION TESTS
  cout << "FRACTION TESTS" << endl;
  cout << setw(10) << "INPUT"
       << setw(10) << "OUTPUT"
       << setw(10) << "EXPECTED"
       << setw(10) << "PASS/FAIL" << endl;
  testTypeInput<fraction>("5", "5");
  testTypeInput<fraction>("5/3", "5/3");
  testTypeInput<fraction>("23/1", "23");
  testTypeInput<fraction>("6/3", "2");
  testTypeInput<fraction>("30/20", "3/2");
  testTypeInput<fraction>("5.1", "51/10");
  testTypeInput<fraction>("5.123", "5123/1000");
  testTypeInput<fraction>("-5", "-5");
  testTypeInput<fraction>("-5/1", "-5");
  testTypeInput<fraction>("-1/2", "-1/2");
  testTypeInput<fraction>("-0.5", "-1/2");
  cout << endl;

  // MIXED NUMBER TESTS
  cout << "MIXED NUMBER TESTS" << endl;
  cout << setw(10) << "INPUT"
       << setw(10) << "OUTPUT"
       << setw(10) << "EXPECTED"
       << setw(10) << "PASS/FAIL" << endl;
  testTypeInput<mixedNumber>("5", "5");
  testTypeInput<mixedNumber>("5/3", "1 2/3");
  testTypeInput<mixedNumber>("23/1", "23");
  testTypeInput<mixedNumber>("6/3", "2");
  testTypeInput<mixedNumber>("30/20", "1 1/2");
  testTypeInput<mixedNumber>("5.1", "5 1/10");
  testTypeInput<mixedNumber>("5.123", "5 123/1000");
  testTypeInput<mixedNumber>("-5", "-5");
  testTypeInput<mixedNumber>("-5/1", "-5");
  testTypeInput<mixedNumber>("-1/2", "-1/2");
  testTypeInput<mixedNumber>("-0.5", "-1/2");


}

template <class T>
void testTypeInput(string input, string expectedOutput) {
  stringstream ss;
  T tested;
  string output;
  ss << input;
  ss >> tested;

  ss.str("");
  ss.clear();

  ss << tested;
  getline(ss, output);

  cout << setw(10) << input;
  cout << setw(10) << output;
  cout << setw(10) << expectedOutput;
  cout << setw(10) << passFail(output, expectedOutput) << endl;
}

string passFail(string output, string expectedOutput) {
  if(output == expectedOutput) {
    return "PASS";
  }
  return "FAIL";
}
