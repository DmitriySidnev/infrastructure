#include <gtest/gtest.h>
#include "merge_sort.h"
#include <vector>

TEST(Merge_sort1, IsMergeSortCorrect) {
  std::vector<int> test1 = { 1, 3, 5, 6, 2, 3, 4, 7 };
  std::vector<int> result1 = { 1, 2, 3, 3, 4, 5, 6, 7 };

  EXPECT_EQ(merge(test1, 0, 3, 7), result1);
}

TEST(Merge_sort2, IsMergeSortCorrect) {
  std::vector<int> test2 = { 1, 1, 1, 3, 3, 3, 2, 2, 2, 4, 4, 4 };
  std::vector<int> result2 = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4 };

  EXPECT_EQ(merge(test2, 0, 5, 11), result2);
}