#include "hash_func.h"
#include <vector>
#include <list>

namespace MyHash {

  size_t hash::hash_func(size_t key) {
  if (key > size - 1) {
    key %= size;
  }
  return key;
}

void hash_chain::insert(size_t key, size_t value) {  // insert value with key
  size_t key_new = hash_func(key);
  if (find(key_new) == buf[key_new].end()) {
    buf[key_new].list::push_back(std::make_pair(key_new, value));
  } else {
    std::list<std::pair<size_t, size_t>>::iterator it = find(key_new);
    it->second = value;
  }
}

void hash_chain::remove(size_t key) {  // delete entry with key
  size_t key_new = hash_func(key);
  std::list<std::pair<size_t, size_t>>::iterator it = find(key_new);
  if (it != buf[key_new].end()) {
    buf[key_new].list::erase(it);
  }
}

size_t hash_chain::get(size_t key) {  // get entry with key
  size_t key_new = hash_func(key);
  std::list<std::pair<size_t, size_t>>::iterator it = find(key_new);
  if (it != buf[key_new].end()) {
    return it->second;
  } else {
    return 0;
  }
}
}  // namespace MyHash
