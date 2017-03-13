#ifndef INCLUDE_HASH_FUNC_H_
#define INCLUDE_HASH_FUNC_H_
#include <vector>
#include <list>

namespace MyHash {
class hash {
 public:
  int size;
  const int step = 37;

 protected:
  hash(int new_size = 1000) : size(new_size) {}
  int hash_func(int key);
};

class hash_mix : hash {
  std::vector<std::pair<int, int>> buf;

 public:
  explicit hash_mix(int a = 1000) : buf(a) {}
};

class hash_chain : hash {
  std::vector<std::list<std::pair<int, int>>> buf;

 private:
  std::list<std::pair<int, int>>::iterator find(int key) {
    std::list<std::pair<int, int>>::iterator it = buf[key].begin();

      while (it != buf[key].end()) {
        if (it->first == key) {
          return it;
        }
        ++it;
      }
      return it;
    }

 public:
  explicit hash_chain(int new_size = 1000) : hash(new_size), buf(new_size) {}
  void insert(int key, int value);
  void remove(int key);
  int get(int key);
};
}  // namespace MyHash

#endif  // INCLUDE_HASH_FUNC_H_
