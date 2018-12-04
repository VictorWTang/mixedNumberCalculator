#include "fraction.h"
#include "streamutilities.h"

std::ostream& operator<<(std::ostream& out, const fraction &frac)
{
  out<<frac.num;
  if(frac.denom != 1)
    out<<"/"<<frac.denom;
  return out;
}

std::istream& operator>>(std::istream& in, fraction &frac)
{
  char junk;
  int possibleNum;
  int possibleDenom;
  bool isNegative = false;
  if(in.peek() == '-') {
    in.get();
    isNegative = true;
  }
  if(streamUtilities::hasNextInt(in))
  {
    in>>possibleNum;
    if(in.peek() == '/' && in >> junk >> possibleDenom) {
      if(possibleDenom == 0) {
        throw(fraction::DIVIDE_BY_ZERO);
      }
      frac.setValue(possibleNum, possibleDenom);
    } else if(in.peek() == '.' && in >> junk >> possibleDenom) {
      std::stringstream ss;
      ss << possibleNum << '.' << possibleDenom;
      double fracDouble;
      ss >> fracDouble;
      frac = fracDouble;
    } else {
      frac.setValue(possibleNum);
    }
    if(isNegative) {
      frac.num *= -1;
    }
    frac.reduce();
    in.clear();
  } else {
    if(isNegative) {
      in.unget();
    }
  }
  return in;
}

fraction operator+(const fraction &x,const fraction &y)
{
  fraction result;
  int num = x.num * y.denom + y.num  * x.denom,
      denom = x.denom * y.denom;
  result.setValue(num,denom);
  return result;
}

fraction operator-(const fraction &x,const fraction &y)
{
  fraction result;
  int num = x.num * y.denom - y.num  * x.denom,
      denom = x.denom * y.denom;
  result.setValue(num,denom);
  return result;
}

fraction operator*(const fraction &x,const fraction &y)
{
  fraction result;
  int num = x.num * y.num,
      denom = x.denom * y.denom;
  result.setValue(num,denom);
  return result;
}

fraction operator/(const fraction &x,const fraction &y)
{
  if(y.num == 0) {
    throw(fraction::DIVIDE_BY_ZERO);
  }
  fraction result;
  int num = x.num * y.denom,
      denom = x.denom * y.num;
  result.setValue(num,denom);
  return result;
}


fraction operator^(const fraction &x,const fraction &y)
{
  double temp1 = pow(pow(x.num, y.num),1./y.denom),
      temp2 = pow(pow(x.denom, y.num),1./y.denom);
  return temp1/temp2;
}


bool operator==(const fraction &x,const fraction &y)
{
  return x.num * y.denom == y.num * x.denom;
}

bool operator>=(const fraction &x,const fraction &y)
{
  return x.num * y.denom >= y.num * x.denom;
}

bool operator<=(const fraction &x,const fraction &y)
{
  return x.num * y.denom <= y.num * x.denom;
}

bool operator!=(const fraction &x,const fraction &y)
{
  return x.num * y.denom != y.num * x.denom;
}

bool operator<(const fraction &x,const fraction &y)
{
  return x.num * y.denom < y.num * x.denom;
}

bool operator>(const fraction &x,const fraction &y)
{
  return x.num * y.denom > y.num * x.denom;
}

