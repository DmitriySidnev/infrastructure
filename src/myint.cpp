#include <myint.h>

namespace MyInt {

Integer Integer::operator+(const Integer& r) {
  Integer res;
  res.val = val + r.val;
  return res;
}
Integer Integer::operator-(const Integer& r) {
  Integer res;
  res.val = val - r.val;
  return res;
}
Integer Integer::operator*(const Integer& r) {
  Integer res;
  res.val = val * r.val;
  return res;
}
Integer Integer::operator/(const Integer& r) {
  Integer res;
  res.val = val / r.val;
  return res;
}
Integer& Integer::operator+=(const Integer& r) {
  val += r.val;
  return *this;
}
Integer& Integer::operator+=(int r) {
  val += r;
  return *this;
}
Integer& Integer::operator++() {
  val++;
  return *this;
}
const Integer Integer::operator++(int) {
  Integer res = *this;
  val += 1;
  return res;
}
bool operator==(const Integer& l, const Integer& r) {
  return l.val == r.val;
}
bool operator!=(const Integer& l, const Integer& r) {
  return l.val != r.val;
}
Integer& operator+(const Integer& l, const Integer& r) {
  Integer res = l;
  res.val += r.val;
  return res;
}
Integer operator+(int l, const Integer& r) {
  Integer res;
  res.val = l + r.val;
  return res;
}
Integer operator+(const Integer& l, int r) {
  Integer res;
  res.val = l.val + r;
  return res;
}
Integer operator+(double l, const Integer& r) {
  Integer res;
  res.val = static_cast<int>(l) + r.val;
  return res;
}
Integer operator+(const Integer& l, double r) {
  Integer res;
  res.val = l.val + static_cast<int>(r);
  return res;
}
Integer& Integer::operator=(const Integer& r) {
  val = r.val;
  return *this;
}
Integer& Integer::operator=(int r) {
  val = r;
  return *this;
}
}  // namespace MyInt
