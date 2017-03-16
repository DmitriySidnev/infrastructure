#include "hash_func.h"
#include <vector>
#include <list>
#include <cstddef>
using std::size_t;

namespace MyHash {

std::size_t Hash::hash_func(std::size_t key) {
  return key % size;
}

void hash_chain::insert(std::size_t key, std::size_t value) {
  std::size_t key_new = hash_func(key);
  std::list<std::pair<size_t, size_t>>::iterator it = find_value(key_new, key);

  if (it == buf[key_new].end()) {
    buf[key_new].list::push_back(std::make_pair(key, value));
  } else {
    it->second = value;
  }
}

void hash_chain::remove(std::size_t key) {  // delete entry with key
  std::size_t key_new = hash_func(key);
  std::list<std::pair<size_t, size_t>>::iterator it = find_value(key_new, key);
  if (it != buf[key_new].end()) {
    buf[key_new].list::erase(it);
  }
}

std::size_t* hash_chain::find(std::size_t key) {  // get entry with key
  std::size_t* out_val = nullptr;
  std::size_t key_new = hash_func(key);
  std::list<std::pair<size_t, size_t>>::iterator it = find_value(key_new, key);
  if (it != buf[key_new].end()) {
    out_val = &it->second;
    return out_val;
  } else {
    return nullptr;
  }
}

std::size_t& hash_chain::operator[](std::size_t key) {
  std::size_t out_val = default_val;
  std::size_t key_new = hash_func(key);
  std::list<std::pair<size_t, size_t>>::iterator it = find_value(key_new, key);
  if (it != buf[key_new].end()) {
    out_val = it->second;
    return out_val;
  } else {
    hash_chain::insert(key, default_val);
    return out_val;
  }
}
}  // namespace MyHash
