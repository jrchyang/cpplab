#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

template<typename K, typename V>
class LRUCache {
public:
 explicit LRUCache(int c) : capacity(c) {
    cout << "init LURCache with " << capacity << " items" << endl;
 }
  ~LRUCache() {
    cout << "LRUCache release" << endl;
  }

  void put(K key, V val) {
    auto it = cache.find(key);
    if (it != cache.end()) {
      it->second->second = val;
      items.splice(items.begin(), items, it->second);
    } else {
      if (items.size() == capacity) {
        auto del = items.back();
        cache.erase(del.first);
        items.pop_back();
      }
      items.emplace_front(key, val);
      cache[key] = items.begin();
    }
  }

  V get(K key) {
    auto it = cache.find(key);
    if (it != cache.end()) {
      items.splice(items.begin(), items, it->second);
      return it->second->second;
    } else {
      throw runtime_error("key not found");
    }
  }

private:
  int capacity;
  list<pair<K, V>> items;
  unordered_map<K, typename list<pair<K, V>>::iterator> cache;
};

int main() {
  LRUCache<string, string> cache(3);

  cache.put("zhangsan", "hello");
  cout << "get zhangsan's value from cache is " << cache.get("zhangsan") << endl;
  cache.put("zhangsan", "world");
  cout << "get zhangsan's value from cache is " << cache.get("zhangsan") << endl;
  cache.put("lisi", "1");
  cache.put("wangwu", "2");
  cache.put("zhaoliu", "3");
  try {
    cout << "get zhangsan's value from cache is(should not exit) " << cache.get("zhangsan") << endl;
  } catch (const runtime_error& e) {
    cout << e.what() << endl;
  }

  return 0;
}
