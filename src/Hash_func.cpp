#include "hash_func.h"
#include <vector>
#include <list>

int MyHash::hash::H(int key) {
  int key_first = key;
  if (key > size - 1) {
    key %= size;
  }
  return key;
}

void MyHash::hash_chain::insert(int key, int value) {  // insert value with key
  key = H(key);
  if (find(key) == buf[key].end()) {
    buf[key].list::push_back(std::make_pair(key, value));
  } else {
    std::list<std::pair<int, int>>::iterator it = find(key);
    (*it).second = value;
  }
}

void MyHash::hash_chain::remove(int key) {  // delete entry with key
  key = H(key);
  std::list<std::pair<int, int>>::iterator it = find(key);
  if (it != buf[key].end()) {
    buf[key].list::erase(it);
  }
}

int MyHash::hash_chain::get(int key) {  // get entry with key
  key = H(key);
  std::list<std::pair<int, int>>::iterator it = find(key);
  if (it != buf[key].end()) {
    return (*it).second;
  } else {
    return 0;
  }
}

