#include <iostream>

namespace MyInt {

class Integer{
  int val;

 public:
  explicit Integer(int v0 = 0) : val(v0) {}
  explicit Integer (double d){
    val = static_cast<int>(d);
  }

  operator int() {
    return val;
  }

  //  basic arithmetic operators	
  const Integer operator+(const Integer& r) {
    Integer res;
    res.val = val + r.val;
    return res;
  }
  const Integer operator-(const Integer& r) {
    Integer res;
    res.val = val - r.val;
    return res;
  }
  const Integer operator*(const Integer& r) {
    Integer res;
    res.val = val * r.val;
    return res;
  }
  const Integer operator/(const Integer& r) {
    Integer res;
    res.val = val / r.val;
    return res;
  }

  //  operator+=
  Integer& operator+=(const Integer& r) {
    val += r.val;
    return *this;
  }
  Integer& operator+=(int r) {
    val += r;
    return *this;
  }

  //  operator increment
  Integer& operator++(){
    val++;
    return *this;
  }
  friend Integer operator++(Integer& l, int) {
    Integer res = l;
    l.val += 1;
    return res;
  }

  //  operator ==, !=
  friend bool operator==(const Integer& l, const Integer& r) {
    return l.val == r.val;
  }
  friend bool operator!=(const Integer& l, const Integer& r) {
    return l.val != r.val;
  }

  //  opeator+
  /*
  friend Integer& operator+(const Integer& l, const Integer& r) {
    Integer res = l;
    res.val += r.val;
    return res;
  }
  */
  friend Integer operator+(int l, const Integer& r) {
    Integer res;
    res.val = l + r.val;
    return res;
  }
  friend Integer operator+(const Integer& l, int r) {
    Integer res;
    res.val = l.val + r;
    return res;
  }
  friend Integer operator+(double l, const Integer& r) {
    Integer res;
    res.val = static_cast<int>(l) + r.val;
    return res;
  }
  friend Integer operator+(const Integer& l, double r) {
    Integer res;
    res.val = l.val + static_cast<int>(r);
    return res;
  }

  //  operator[]
  Integer& operator[](const Integer& a) {
    Integer res = a;
    return res;
  }
  //  operator=
  Integer& operator=(const Integer& r) {
    val = r.val;
    return *this;	
  }
  Integer& operator=(int r) {
    val = r;
    return *this;
  }
  //  cin >>, cout <<
  friend std::ostream& operator<<(std::ostream& outStream, const Integer& r) {
    outStream << r.val;
    return outStream;
  }
  friend std::istream& operator>>(std::istream& inStream, Integer& r) {
    inStream >> r.val;
    return inStream;
  }
  //  get()
  int get() const {
    return val;
  }
};	
} //  namespace MyInt

int main(){
  MyInt::Integer x(5), y(3.5), z, xf[10];
  z = x + y;
  int f = z.get();

  if (x != y) {
    std::cout << "x != y" << std::endl;
  } else {
    std::cout << "x == y" << std::endl;
  }

  double d = 2.0;
  z = 1 + x + y;
  z = x;
  2 + x + 5.6;
  std::cout << z + 20.1 << std::endl;

  xf[x] = y + 45;
  xf[9] = 34;

  std::cout << xf[x] << std::endl << xf[9] << std::endl;

  MyInt::Integer aa = ++x;
  MyInt::Integer bb = y++;
  y++;
  ++xf[0];

  xf[2] += x;
  xf[3] += 1;

  return 0;
}
