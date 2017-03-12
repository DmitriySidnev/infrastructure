#include <gtest/gtest.h>
#include "hash_func.h"
#include <vector>

TEST(Hash_table, IsHashTableOK) {
  MyHash::hash_chain k;
  k.insert(1, 3);
  k.insert(5, 9);
  k.insert(104, 12);
  EXPECT_EQ(k.get(1), 3);
  EXPECT_EQ(k.get(5), 9);
}
