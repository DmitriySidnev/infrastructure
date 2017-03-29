#include <gtest/gtest.h>
#include "hash_func_templ.h"
#include <vector>
#include <cstddef>
#include <string>
#include <map>
#include <random>
#include <vector>

TEST(Hash_table1, IsHashTable_OK) {
  MyHash::HashChain<int, int> sample(100, [&](const int& key, size_t size) {
    return (key * 37) % size;
  });

  std::random_device rnd;
  std::map<int, int> mapHash;

  for (int i = 0; i < 1000; i++) {
    int rnd_key = rnd();
    int rnd_val = rnd();
    sample[rnd_key] = rnd_val;
    mapHash[rnd_key] = rnd_val;
  }

  for (auto hash : mapHash) {
    EXPECT_EQ(sample[hash.first], hash.second);
  }
  
}

TEST(Hash_table2, IsHashTable_string_OK) {
  MyHash::HashChain<std::string, unsigned int> sample(500);
  std::random_device rnd;
  std::string str;
  std::map<std::string, unsigned int> mapHash;

  for (int j = 0; j < 1000; j++) {
    str.resize(rnd() % 20);
    for (int i = 0; i < str.size(); i++) {
      str[i] = rnd() % 57 + 65;
    }
    int rnd_val = rnd();
    sample[str] = rnd_val;
    mapHash[str] = rnd_val;
  }

  for (auto hash : mapHash) {
    EXPECT_EQ(sample[hash.first], hash.second);
  }
}

TEST(Hash_table3, IsHashTable_operator_OK) {
  MyHash::HashChain<float, unsigned int> sample(500, [&](const float& key, size_t size) {
    const size_t* hash = reinterpret_cast<const size_t*>(&key);
    return *hash % size;
  });

  std::random_device rnd;
  std::map<float, int> mapHash;

  for (int j = 0; j < 1000; j++) {
    float rnd_key = static_cast<float>(rnd()) / 1000;
    unsigned int rnd_val = rnd();
    sample[rnd_key] = rnd_val;
    mapHash[rnd_key] = rnd_val;
  }

  for (auto hash : mapHash) {
    EXPECT_EQ(sample[hash.first], hash.second);
  }
}

TEST(Hash_table4, IsHashTable_char_OK) {
  MyHash::HashChain<char, unsigned int> sample(500, MyHash::MyHashFunction<char>);

  std::random_device rnd;
  std::map<char, int> mapHash;

  for (int j = 0; j < 1000; j++) {
    char rnd_key = static_cast<char>(rnd());
    unsigned int rnd_val = rnd();
    //sample[rnd_key] = rnd_val;
    sample.insert(rnd_key, rnd_val);
    mapHash[rnd_key] = rnd_val;
  }

  for (auto hash : mapHash) {
    EXPECT_EQ(sample[hash.first], hash.second);
  }
}

TEST(Hash_table5, IsHashTable_string_and_remove_OK) {
  MyHash::HashChain<std::string, int> sample;
  std::string key_str;
  std::random_device rnd;
  std::map<std::string, int> mapHash;
  std::vector<std::string> vec(1000);

  for (int j = 0; j < 1000; j++) {
    key_str.resize(rnd() % 20);
    for (int i = 0; i < key_str.size(); i++) {
      key_str[i] = rnd() % 57 + 65;
    }
    vec[j] = key_str;
    mapHash[key_str] = j;
    sample[key_str] = j;
  }
  for (int j = 0; j < 1000; j++) {
    EXPECT_EQ(*(sample.find(vec[j])), mapHash[vec[j]]);
  }

  for (int j = 234; j < 658; j++) {
    sample.remove(vec[j]);
  }
  for (int j = 234; j < 658; j++) {
    EXPECT_EQ(sample.find(vec[j]), nullptr);
  }
}
