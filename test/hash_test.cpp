#include <gtest/gtest.h>
#include "hash_func.h"
#include <vector>
#include <cstddef>

TEST(Hash_table1, IsHashTable_Insert_OK) {
  MyHash::hash_chain k(100);
  k.insert(1, 3);
  k.insert(5, 9);
  k.insert(104, 12);
  EXPECT_EQ(*(k.find(1)), 3);
  EXPECT_EQ(*(k.find(5)), 9);

  for (std::size_t i = 1; i < 1003; i++) {
    std::size_t x = 23 * i;
    k.insert(i, x);
  }
  for (std::size_t i = 1; i < 1003; i++) {
    std::size_t* x = k.find(i);
    std::size_t y = 23 * i;
    EXPECT_EQ(*x, y);
  }

  for (std::size_t i = 265; i < 643; i++) {
    k.remove(i);
  }
  for (std::size_t i = 265; i < 643; i++) {
    std::size_t* x = k.find(i);
    EXPECT_EQ(x, nullptr);
  }
}

TEST(Hash_table2, IsHashTable_Remove_OK) {
  MyHash::hash_chain k;
  k.insert(1, 3);
  k.insert(5, 9);
  k.insert(104, 12);
  k.remove(5);
  EXPECT_EQ(*(k.find(1)), 3);
  EXPECT_EQ(*(k.find(5)), 0);
  EXPECT_EQ(*(k.find(104)), 12);
  k.remove(104);
  EXPECT_EQ(*(k.find(104)), 0);
  k.insert(101, 34);
  EXPECT_EQ(*(k.find(101)), 34);
  EXPECT_EQ(*(k.find(1)), 3);
}
