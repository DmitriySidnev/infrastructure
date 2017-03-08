#include <gtest/gtest.h>
#include "add_mul.h"

TEST(Addition, CanAddTwoNumbers) {
  EXPECT_EQ(add(2, 2), 4);
  EXPECT_EQ(add(-2, 2), 0);
}

TEST(Multiply, CanMulTwoNumbers) {
	EXPECT_EQ(mul(3, 5), 15);
}
