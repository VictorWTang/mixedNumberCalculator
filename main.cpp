#include <iostream>
#include <random> // TODO Remove when done testing
#include "mixednumber.h"

using namespace std;

struct testPair {
  string input, expectedOutput;
};

void runTests();
string passFail(string output, string expectedOutput);
string generateRandomTrash();

template <class T>
void testTypeInput(string input, string expectedOutput);

template <class T>
bool testStreamIntegrity(string input, string expectedOutput);

template <class T>
void testMultipleStreamIntegrity(string input, string expectedOutput);

static default_random_engine generator;
static uniform_int_distribution<int> charDistribution(' ', '~');

int main()
{
//  generator.seed(static_cast<unsigned int>(time(nullptr)));
//  runTests();




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
  testTypeInput<mixedNumber>("1 1/2", "1 1/2");
  testTypeInput<mixedNumber>("-1 1/2", "-1 1/2");
  testTypeInput<mixedNumber>("-3/2", "-1 1/2");
  cout << endl;


  cout << "FRACTION INTEGRITY TESTS" << endl;
  testMultipleStreamIntegrity<fraction>("5", "5");
  testMultipleStreamIntegrity<fraction>("5/3", "5/3");
  testMultipleStreamIntegrity<fraction>("23/1", "23");
  testMultipleStreamIntegrity<fraction>("6/3", "2");
  testMultipleStreamIntegrity<fraction>("30/20", "3/2");
  testMultipleStreamIntegrity<fraction>("5.1", "51/10");
  testMultipleStreamIntegrity<fraction>("5.123", "5123/1000");
  testMultipleStreamIntegrity<fraction>("-5", "-5");
  testMultipleStreamIntegrity<fraction>("-5/1", "-5");
  testMultipleStreamIntegrity<fraction>("-1/2", "-1/2");
  testMultipleStreamIntegrity<fraction>("-0.5", "-1/2");
  cout << endl;


  cout << "MIXED NUMBER INTEGRITY TESTS" << endl;
  testMultipleStreamIntegrity<mixedNumber>("5", "5");
  testMultipleStreamIntegrity<mixedNumber>("5/3", "1 2/3");
  testMultipleStreamIntegrity<mixedNumber>("23/1", "23");
  testMultipleStreamIntegrity<mixedNumber>("6/3", "2");
  testMultipleStreamIntegrity<mixedNumber>("30/20", "1 1/2");
  testMultipleStreamIntegrity<mixedNumber>("5.1", "5 1/10");
  testMultipleStreamIntegrity<mixedNumber>("5.123", "5 123/1000");
  testMultipleStreamIntegrity<mixedNumber>("-5", "-5");
  testMultipleStreamIntegrity<mixedNumber>("-5/1", "-5");
  testMultipleStreamIntegrity<mixedNumber>("-1/2", "-1/2");
  testMultipleStreamIntegrity<mixedNumber>("1 1/2", "1 1/2");
  testMultipleStreamIntegrity<mixedNumber>("-1 1/2", "-1 1/2");
  testMultipleStreamIntegrity<mixedNumber>("-3/2", "-1 1/2");
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

template <class T>
bool testStreamIntegrity(string input, string expectedOutput) {
  stringstream ss;
  T test;
  string output;
  string restOfStream;

  string randomChars = generateRandomTrash();

  ss << input << randomChars;
  ss >> test;
  getline(ss, restOfStream);

  ss.str("");
  ss.clear();
  ss << test;
  getline(ss, output);

  if(randomChars != restOfStream) {
    cout << setw(10) << input
         << setw(10) << output
         << setw(10) << expectedOutput
         << setw(6) << restOfStream
         << setw(6) << randomChars
         << setw(5) << "FAIL" << endl;
    return false;
  }
  return true;
}

template <class T>
void testMultipleStreamIntegrity(string input, string expectedOutput) {
  int succeedCount = 0;
  int testCount = 1000;
  for(int i = 0; i < testCount; i++) {
    succeedCount += testStreamIntegrity<T>(input, expectedOutput);
  }
  cout << "TESTS: " << succeedCount << "/" << testCount << endl;
}

string generateRandomTrash() {
  string randomChars = "";
  char randomChar;
  for(int i = 0; i < 5; i++) {
    do{
      randomChar = static_cast<char>(charDistribution(generator));
    } while((i == 0 || i == 1) && randomChar >= '0' && randomChar <= '9');
    randomChars += randomChar;
  }
  return randomChars;
}


string passFail(string output, string expectedOutput) {
  if(output == expectedOutput) {
    return "PASS";
  }
  return "FAIL";
}
