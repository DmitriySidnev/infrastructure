#include "hash_func.h"
#include <vector>
#include <list>

namespace MyHash {

int hash::hash_func(int key) {
  if (key > size - 1) {
    key %= size;
  }
  return key;
}

void hash_chain::insert(int key, int value) {  // insert value with key
  int key_new = hash_func(key);
  if (find(key_new) == buf[key_new].end()) {
    buf[key_new].list::push_back(std::make_pair(key_new, value));
  } else {
    std::list<std::pair<int, int>>::iterator it = find(key_new);
    it->second = value;
  }
}

void hash_chain::remove(int key) {  // delete entry with key
  int key_new = hash_func(key);
  std::list<std::pair<int, int>>::iterator it = find(key_new);
  if (it != buf[key_new].end()) {
    buf[key_new].list::erase(it);
  }
}

int hash_chain::get(int key) {  // get entry with key
  int key_new = hash_func(key);
  std::list<std::pair<int, int>>::iterator it = find(key_new);
  if (it != buf[key_new].end()) {
    return it->second;
  } else {
    return 0;
  }
}
}  // namespace MyHash
