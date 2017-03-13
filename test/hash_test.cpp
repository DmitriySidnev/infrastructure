#include <gtest/gtest.h>
#include "hash_func.h"
#include <vector>

TEST(Hash_table1, IsHashTable_Insert_OK) {
  MyHash::hash_chain k(100);
  k.insert(1, 3);
  k.insert(5, 9);
  k.insert(104, 12);
  EXPECT_EQ(k.get(1), 3);
  EXPECT_EQ(k.get(5), 9);

  for (int i = 1; i < 1003; i++) {
    size_t x = 23 * i;
    k.insert(i, x);
  }
  for (int i = 1; i < 1003; i++) {
    size_t x = k.get(i);
    size_t y = 23 * i;
    EXPECT_EQ(x, y);
  }

  for (int i = 265; i < 643; i++) {
    k.remove(i);
  }
  for (int i = 265; i < 643; i++) {
    size_t x = k.get(i);
    EXPECT_EQ(x, 0);
  }
}

TEST(Hash_table2, IsHashTable_Remove_OK) {
  MyHash::hash_chain k;
  k.insert(1, 3);
  k.insert(5, 9);
  k.insert(104, 12);
  k.remove(5);
  EXPECT_EQ(k.get(1), 3);
  EXPECT_EQ(k.get(5), 0);
  EXPECT_EQ(k.get(104), 12);
  k.remove(104);
  EXPECT_EQ(k.get(104), 0);
  k.insert(101, 34);
  EXPECT_EQ(k.get(101), 34);
  EXPECT_EQ(k.get(1), 3);
}
