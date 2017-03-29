#ifndef INCLUDE_HASH_FUNC_TEMPL_H_
#define INCLUDE_HASH_FUNC_TEMPL_H_
#include <vector>
#include <list>
#include <cstddef>
#include <functional>
using std::size_t;

namespace MyHash {

template<class Key>
size_t defaultHashFunction(const Key& key, size_t size = 1000) {
  return static_cast<size_t>(key) % size;
}

template<>
size_t defaultHashFunction<std::string>(const std::string& key, size_t size) {
  if (key.size() == 0) {
    return 0;
  } else {
    return static_cast<size_t>(key[0] * key[key.size() - 1] * key[key.size() / 2]) % size;
  }
}

template<>
size_t defaultHashFunction<float>(const float& key, size_t size) {
  const size_t* hash = reinterpret_cast<const size_t*>(&key);
  return *hash % size;
}

template<class Key>
size_t MyHashFunction(const Key& key, size_t size = 1023) {
  return (static_cast<size_t>(key) & size) % size;
}

template<>
size_t MyHashFunction<float>(const float& key, size_t size) {
  const size_t* hash = reinterpret_cast<const size_t*>(&key);
  return (*hash & size) % size;
}

template<class Key>
class Hash {
 public:
  using HashFunction = std::function<size_t(const Key&, size_t)>;
  size_t size;
  HashFunction hash_func;

 protected:
  explicit Hash(size_t table_size = 1000, HashFunction f = defaultHashFunction<Key>) :
    size(table_size), hash_func(f) {
  }
};

template<class Key, class Value>
class HashMix : Hash<Key> {
  std::vector<std::pair<Key, Value>> table;
  const size_t step = 37;

 public:
  explicit HashMix(size_t table_size = 1000) : table(table_size) {}
};

template<class Key, class Value>
class HashChain : public Hash<Key> {
  std::vector<std::list<std::pair<Key, Value>>> table;
  using hash_cell = typename std::list<std::pair<Key, Value>>::iterator;
  using HashFunction = std::function<size_t(const Key&, size_t)>;

 private:
  hash_cell find_value(const size_t hash, const Key key) {
    auto it = table[hash].begin();

    while (it != table[hash].end()) {
      if (it->first == key) {
        return it;
      }
      ++it;
    }
  return it;
  }

 public:
  explicit HashChain(size_t table_size = 1000, HashFunction f = defaultHashFunction<Key>) :
    Hash<Key>(table_size, f), table(table_size) {
  }

  void insert(const Key key, const Value value) {
    size_t hash = Hash<Key>::hash_func(key, Hash<Key>::size);
    hash_cell it = find_value(hash, key);

    if (it == table[hash].end()) {
      table[hash].push_back(std::make_pair(key, value));
    } else {
      it->second = value;
    }
  }

  void remove(Key key) {
    size_t hash = Hash<Key>::hash_func(key, Hash<Key>::size);
    auto it = find_value(hash, key);

    if (it != table[hash].end()) {
      table[hash].erase(it);
    }
  }

  Value* find(const Key key) {
    Value* out_val = nullptr;
    size_t hash = Hash<Key>::hash_func(key, Hash<Key>::size);
    auto it = find_value(hash, key);

    if (it != table[hash].end()) {
      out_val = &it->second;
      return out_val;
    } else {
      return nullptr;
    }
  }

  Value& operator[](const Key key) {
    Value* out_val = find(key);
    if (out_val == nullptr) {
      HashChain::insert(key, Value());
    }
    out_val = find(key);
    return *out_val;
  }
};
}  // namespace MyHash

#endif  // INCLUDE_HASH_FUNC_TEMPL_H_
