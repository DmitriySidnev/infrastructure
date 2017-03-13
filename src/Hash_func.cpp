#include "hash_func.h"
#include <vector>
#include <list>
#include <cstddef>
using std::size_t;

namespace MyHash {

  std::size_t hash::hash_func(std::size_t key) {
  if (key > size - 1) {
    key %= size;
  }
  return key;
}

void hash_chain::insert(std::size_t key, std::size_t value) {
  std::size_t key_new = hash_func(key);
  std::list<std::pair<size_t, size_t>>::iterator it = find(key_new, key);

  if (it == buf[key_new].end()) {
    buf[key_new].list::push_back(std::make_pair(key_new, value));
  } else {
    it->second = value;
  }
}

void hash_chain::remove(std::size_t key) {  // delete entry with key
  std::size_t key_new = hash_func(key);
  std::list<std::pair<size_t, size_t>>::iterator it = find(key_new, key);
  if (it != buf[key_new].end()) {
    buf[key_new].list::erase(it);
  }
}

std::size_t hash_chain::get(std::size_t key) {  // get entry with key
  std::size_t key_new = hash_func(key);
  std::list<std::pair<size_t, size_t>>::iterator it = find(key_new, key);
  if (it != buf[key_new].end()) {
    return it->second;
  } else {
    return 0;
  }
}
}  // namespace MyHash
