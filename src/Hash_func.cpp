#include "hash_func.h"
#include <vector>
#include <list>

class MyHash::hash{
 protected:
  int key;
  int size;
  const int step = 37;

  explicit hash(int a = 1000) {
    size = a;
  }

  int H(int key) {
    int key_first = key;
    if (key > size - 1) {
      key %= size;
    }

    return key;
  }
};

class MyHash::hash_mix : hash {
  std::vector<std::pair<int, int>> buf;

 public:
  explicit hash_mix(int a = 1000) : buf(size) {}
};

class MyHash::hash_chain : hash {
  std::vector<std::list<std::pair<int, int>>> buf;

 private:
  std::list<std::pair<int, int>>::iterator find(int key) {
    std::list<std::pair<int, int>>::iterator it = buf[key].begin();

    while (it != buf[key].end()) {
      if ((*it).first == key) {
        return it;
      }
      ++it;
    }

    return it;
  }

 public:
  explicit hash_chain(int a = 1000) : buf(size) {}

  void insert(int key, int value) {  // insert value with key
    key = H(key);
    if (find(key) == buf[key].end()) {
      buf[key].list::push_back(std::make_pair(key, value));
    } else {
      std::list<std::pair<int, int>>::iterator it = find(key);
      (*it).second = value;
    }
  }

  void remove(int key) {  // delete entry with key
    key = H(key);
    std::list<std::pair<int, int>>::iterator it = find(key);
    if (it != buf[key].end()) {
      buf[key].list::erase(it);
    }
  }

  int get(int key) {  // get entry with key
    key = H(key);
    std::list<std::pair<int, int>>::iterator it = find(key);
    if (it != buf[key].end()) {
      return (*it).second;
    } else {
      return 0;
    }
  }
};
