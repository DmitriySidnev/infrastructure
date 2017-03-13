#ifndef INCLUDE_HASH_FUNC_H_
#define INCLUDE_HASH_FUNC_H_
#include <vector>
#include <list>
#include <cstddef>
using std::size_t;

namespace MyHash {
class hash {
 public:
  std::size_t size;
  const std::size_t step = 37;

 protected:
  explicit hash(std::size_t new_s = 1000) : size(new_s) {}
  std::size_t hash_func(std::size_t key);
};

class hash_mix : hash {
  std::vector<std::pair<std::size_t, std::size_t>> buf;

 public:
  explicit hash_mix(std::size_t a = 1000) : buf(a) {}
};

class hash_chain : hash {
  std::vector<std::list<std::pair<std::size_t, std::size_t>>> buf;

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
  explicit hash_chain(size_t new_s = 1000) : hash(new_s), buf(new_s) {}
  void insert(std::size_t key, std::size_t value);
  void remove(std::size_t key);
  std::size_t get(std::size_t key);
};
}  // namespace MyHash

#endif  // INCLUDE_HASH_FUNC_H_
