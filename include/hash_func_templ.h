#ifndef INCLUDE_HASH_FUNC_TEMPL_H_
#define INCLUDE_HASH_FUNC_TEMPL_H_
#include <vector>
#include <list>
#include <cstddef>
using std::size_t;

namespace MyHash {
template<class T1> class Hash {
 public:
  std::size_t size;
  const std::size_t step = 37;
  const std::size_t default_val = 0;

 protected:
  explicit Hash(std::size_t new_s = 1000) : size(new_s) {}
  std::size_t hash_func(const T1* key) {
    size_t tmp = static_cast<size_t>(*key);
    return tmp % size;
  }
};

template<class T1, class T2> class hash_mix : Hash<T1> {
  std::vector<std::pair<T1, T2>> buf;

 public:
  explicit hash_mix(std::size_t a = 1000) : buf(a) {}
};

template<class T1, class T2> class hash_chain : Hash<T1> {
  std::vector<std::list<std::pair<T1, T2>>> buf;

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
  explicit hash_chain(size_t new_s = 1000) : Hash<T1>(new_s), buf(new_s) {}

  void insert(const T1 key, const T2 value) {
    std::size_t key_new = hash_func(&key);
    typename std::list<std::pair<T1, T2>>::iterator it = find_value(key_new, key);

    if (it == buf[key_new].end()) {
      buf[key_new].std::list::push_back(std::make_pair(key, value));
    } else {
      it->second = value;
    }
  }

  void remove(T1 key) {
    std::size_t key_new = hash_func(&key);
    typename std::list<std::pair<T1, T2>>::iterator it = find_value(key_new, key);
    if (it != buf[key_new].end()) {
      buf[key_new].std::list::erase(it);
    }
  }

  T2* find(const T1 key) {
    T2* out_val = nullptr;
    std::size_t key_new = hash_func(&key);
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
      hash_chain::insert(key, static_cast<T2>(default_val));  // insert pair(key, value = 0)
    }
    out_val = find(key);
    return *out_val;
  }
};
}  // namespace MyHash

#endif  // INCLUDE_HASH_FUNC_TEMPL_H_
