#ifndef INCLUDE_MYINT_H_
#define INCLUDE_MYINT_H_

#include <iostream>

namespace MyInt {

class Integer {
  int val;

 public:
  explicit Integer(int v0 = 0) : val(v0) {}
  explicit Integer(double d) {
    val = static_cast<int>(d);
  }

  operator int() {
    return val;
  }

  Integer operator+(const Integer& r);
  Integer operator-(const Integer& r);
  Integer operator*(const Integer& r);
  Integer operator/(const Integer& r);
  Integer& operator+=(const Integer& r);
  Integer& operator+=(int r);
  Integer& operator++();
  const Integer operator++(int);
  friend bool operator==(const Integer& l, const Integer& r);
  friend bool operator!=(const Integer& l, const Integer& r);
  friend Integer& operator+(const Integer& l, const Integer& r);
  friend Integer operator+(int l, const Integer& r);
  friend Integer operator+(const Integer& l, int r);
  friend Integer operator+(double l, const Integer& r);
  friend Integer operator+(const Integer& l, double r);
  // Integer& operator[](const Integer& a);
  Integer& operator=(const Integer& r);
  Integer& operator=(int r);

  friend std::ostream& operator<<(std::ostream& outStream, const Integer& r) {
    outStream << r.val;
    return outStream;
  }
  friend std::istream& operator >>(std::istream& inStream, Integer& r) {
    inStream >> r.val;
    return inStream;
  }
  int get() {
    return Integer::val;
  }
};
}  // namespace MyInt

#endif  // INCLUDE_MYINT_H_H_
