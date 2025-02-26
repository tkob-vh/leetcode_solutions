// @leet start
#include <list>
#include <unordered_map>
class LRUCache {
public:
  LRUCache(int capacity) : m_capacity(capacity) {}

  int get(int key) {
    auto iter = m_map.find(key);
    if (iter == m_map.end()) {
      return -1;
    } else {
      m_list.splice(m_list.begin(), m_list, iter->second);
      return iter->second->second;
    }
  }

  void put(int key, int value) {
    auto iter = m_map.find(key);
    if (iter != m_map.end()) {
      m_list.splice(m_list.begin(), m_list, iter->second);
      iter->second->second = value;
      return;
    }

    if (m_map.size() == m_capacity) {
      int evict_key = m_list.back().first;
      m_list.pop_back();
      m_map.erase(evict_key);
    }
    m_list.emplace_front(std::pair(key, value));
    m_map[key] = m_list.begin();
  }

private:
  int m_capacity;
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_map;
  std::list<std::pair<int, int>> m_list;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @leet end
