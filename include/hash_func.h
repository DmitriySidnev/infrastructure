#ifndef INCLUDE_HASH_FUNC_H_
#define INCLUDE_HASH_FUNC_H_
#include <vector>
#include <list>

namespace MyHash {
class hash {
 public:
  size_t size;
  const size_t step = 37;

 protected:
  explicit hash(size_t new_size = 1000) : size(new_size) {}
  size_t hash_func(size_t key);
};

class hash_mix : hash {
  std::vector<std::pair<size_t, size_t>> buf;

 public:
  explicit hash_mix(size_t a = 1000) : buf(a) {}
};

class hash_chain : hash {
  std::vector<std::list<std::pair<size_t, size_t>>> buf;

 private:
  std::list<std::pair<size_t, size_t>>::iterator find(size_t key) {
    std::list<std::pair<size_t, size_t>>::iterator it = buf[key].begin();

      while (it != buf[key].end()) {
        if (it->first == key) {
          return it;
        }
        ++it;
      }
    return it;
  }

 public:
  explicit hash_chain(size_t new_size = 1000) : hash(new_size), buf(new_size) {}
  void insert(size_t key, size_t value);
  void remove(size_t key);
  size_t get(size_t key);
};
}  // namespace MyHash

#endif  // INCLUDE_HASH_FUNC_H_
