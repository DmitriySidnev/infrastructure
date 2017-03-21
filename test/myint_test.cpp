#include <gtest/gtest.h>
#include <myint.h>
#include <iostream>

TEST(MyInt, Operators_is_OK) {
  MyInt::Integer x, y, arr[30];
  int a = 0, b = 0, c[30];
  for (MyInt::Integer i; i != 30; ++i) {
    arr[i] = x++;
    c[i] = a++;
    y++;
    b++;
    MyInt::Integer tmp = arr[i];
    EXPECT_EQ(x.get(), a);
    EXPECT_EQ(y.get(), b);
    EXPECT_EQ(tmp.get(), c[i]);
  }

  MyInt::Integer s1, s2, s3;
  s1 = 50;
  s2 = s1 + 50;
  s3 = 100 + s2 + s1 + 50;
  EXPECT_EQ(s1.get(), 50);
  EXPECT_EQ(s2.get(), 100);
  EXPECT_EQ(s3.get(), 300);

  s1 += s2;
  s3 += 30;
  EXPECT_EQ(s1.get(), 150);
  EXPECT_EQ(s3.get(), 330);

  bool r1 = (s1 == s2);
  EXPECT_EQ(r1, 0);
  r1 = (s1 == 150);
  EXPECT_EQ(r1, 1);
}
