#include "hash_func_templ.h"
#include <vector>
#include <list>
#include <cstddef>
using std::size_t;

namespace MyHash {
/*
template<class T1> size_t Hash<T1>::hash_func(T1* key) {
  return dynamic_cast<size_t>(*key) % size;
}
*/
/*
template<class T1, class T2> void hash_chain<T1, T2>::insert(const T1 key, const T2 value) {
  std::size_t key_new = hash_func(&key);
  std::list<std::pair<T1, T2>>::iterator it = find_value(key_new, key);

  if (it == buf[key_new].end()) {
    buf[key_new].list::push_back(std::make_pair(key, value));
  } else {
    it->second = value;
  }
}
*/
/*
template<class T1, class T2> void hash_chain<T1, T2>::remove(T1 key) {  // delete entry with key
  std::size_t key_new = hash_func(&key);
  std::list<std::pair<T1, T2>>::iterator it = find_value(key_new, key);
  if (it != buf[key_new].end()) {
    buf[key_new].list::erase(it);
  }
}
*/
/*
template<class T1, class T2> T2* hash_chain<T1, T2>::find(const T1 key) {  // get entry with key
  T2* out_val = nullptr;
  std::size_t key_new = hash_func(&key);
  std::list<std::pair<T1, T2>>::iterator it = find_value(key_new, key);
  if (it != buf[key_new].end()) {
    out_val = &it->second;
    return out_val;
  } else {
    return nullptr;
  }
}
*/
/*
template<class T1, class T2> T2& hash_chain<T1, T2>::operator[](const T1 key) {
  T2* out_val = find(key);
  if (out_val == nullptr) {
    hash_chain::insert(key, dynamic_cast<T2>(default_val));  // insert pair(key, value = 0)
  }
  out_val = find(key);
  return *out_val;
}
*/
}  // namespace MyHash
