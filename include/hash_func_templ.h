#ifndef INCLUDE_HASH_FUNC_TEMPL_H_
#define INCLUDE_HASH_FUNC_TEMPL_H_
#include <vector>
#include <list>
#include <cstddef>
#include <functional>
using std::size_t;

namespace MyHash {
template<class T1>
size_t functDef(const T1& key, size_t size = 1000) {
  size_t tmp = static_cast<size_t>(key);
  tmp %= size;
  return tmp;
}

template<class T1>
size_t functMy(const T1& key, size_t size = 1000) {
  size_t tmp = static_cast<size_t>(key);
  tmp = (tmp % size) + 37;
  if (tmp >= size) {
    tmp = tmp = size - 1;
  } else if (tmp < 0) {
    tmp = 0;
  }
  return tmp;
}

template<class T1> class Hash {
 public:
  size_t size;
  std::function<size_t(const T1&, size_t)> hash_func;
  const size_t step = 37;
  const size_t default_val = 0;

 protected:
  explicit Hash(size_t new_s = 1000, std::function<size_t(const T1&, size_t)> f = functDef<T1>) : 
  size(new_s), hash_func(f) {}
};

template<class T1, class T2> class hash_mix : Hash<T1> {
  std::vector<std::pair<T1, T2>> buf;

 public:
  explicit hash_mix(size_t a = 1000) : buf(a) {}
};

template<class T1, class T2> class hash_chain : public Hash<T1> {
  std::vector<std::list<std::pair<T1, T2>>> buf;
  // using hash_cell = std::list<std::pair<T1, T2>>::iterator;

 private:
  typename std::list<std::pair<T1, T2>>::iterator find_value(const size_t key, const  T1 key_vis) {
    typename std::list<std::pair<T1, T2>>::iterator it = buf[key].begin();

    while (it != buf[key].end()) {
      if (it->first == key_vis) {
        return it;
      }
      ++it;
    }
    return it;
  }

 public:
  explicit hash_chain(size_t new_s = 1000, std::function<size_t(const T1&, size_t)> f = functDef<T1>) : 
  Hash<T1>(new_s, f), buf(new_s) {}

  void insert(const T1 key, const T2 value) {
    size_t key_new = Hash<T1>::hash_func(key, Hash<T1>::size);
    typename std::list<std::pair<T1, T2>>::iterator it = find_value(key_new, key);

    if (it == buf[key_new].end()) {
      buf[key_new].push_back(std::make_pair(key, value));
    } else {
      it->second = value;
    }
  }

  void remove(T1 key) {
    size_t key_new = Hash<T1>::hash_func(key, Hash<T1>::size);
    typename std::list<std::pair<T1, T2>>::iterator it = find_value(key_new, key);

    if (it != buf[key_new].end()) {
      buf[key_new].erase(it);
    }
  }

  T2* find(const T1 key) {
    T2* out_val = nullptr;
    size_t key_new = Hash<T1>::hash_func(key, Hash<T1>::size);
    typename std::list<std::pair<T1, T2>>::iterator it = find_value(key_new, key);

    if (it != buf[key_new].end()) {
      out_val = &it->second;
      return out_val;
    } else {
      return nullptr;
    }
  }

  T2& operator[](const T1 key) {
    T2* out_val = find(key);
    if (out_val == nullptr) {
      hash_chain::insert(key, T2());  // insert pair(key, value = 0)
    }
    out_val = find(key);
    return *out_val;
  }
};
}  // namespace MyHash

#endif  // INCLUDE_HASH_FUNC_TEMPL_H_
