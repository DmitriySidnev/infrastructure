#include <gtest/gtest.h>
#include "hash_func_templ.h"
#include <vector>
#include <cstddef>
#include <string>

TEST(Hash_table1, IsHashTable_Insert_OK) {
  MyHash::hash_chain<int, double> k(100);
  k.insert(1, 3.1);
  k.insert(5, 9.6);
  k.insert(104, 12.2);
  EXPECT_EQ(*(k.find(1)), 3.1);
  EXPECT_EQ(*(k.find(5)), 9.6);

  for (int i = 1; i < 1003; i++) {
    double x = 23 * i;
    k.insert(i, x);
  }
  for (int i = 1; i < 1003; i++) {
    double* x = k.find(i);
    double y = 23 * i;
    EXPECT_EQ(*x, y);
  }

  for (int i = 265; i < 643; i++) {
    k.remove(i);
  }
  for (int i = 265; i < 643; i++) {
    double* x = k.find(i);
    EXPECT_EQ(x, nullptr);
  }
}

TEST(Hash_table2, IsHashTable_Remove_and_string_OK) {
  MyHash::hash_chain<int, std::string> k;
  k.insert(1, "first");
  k.insert(5, "fifth");
  k.insert(104, "one zero four");
  k.remove(5);
  EXPECT_EQ(*(k.find(1)), "first");
  EXPECT_EQ(k.find(5), nullptr);
  EXPECT_EQ(*(k.find(104)), "one zero four");
  k.remove(104);
  EXPECT_EQ(k.find(104), nullptr);
  k.insert(101, "101");
  EXPECT_EQ(*(k.find(101)), "101");
  EXPECT_EQ(*(k.find(1)), "first");
}

TEST(Hash_table3, IsHashTable_operator_OK) {
  MyHash::hash_chain<float, int> k;
  k[1.0] = 2;
  EXPECT_EQ(*(k.find(1.0)), 2);
  EXPECT_EQ(k[1.0], 2);
  int x = k[1.0];
  EXPECT_EQ(x, 2);
  EXPECT_EQ(k[2], 0);
}

TEST(Hash_table4, IsHashTable_char_OK) {
  MyHash::hash_chain<char, int> k;
  k.insert('x', 3);
  EXPECT_EQ(*(k.find('x')), 3);
}
/*
TEST(Hash_table5, IsHashTable_string_OK) {
  MyHash::hash_chain<std::string, int> k;
  k.insert("dick", 3);
  EXPECT_EQ(*(k.find("dick")), 3);
}
*/
