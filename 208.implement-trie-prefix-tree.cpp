// @leet start
#include <array>
#include <string>
using namespace std;

class Trie {
public:
  Trie() { m_root = new TrieNode(); }

  void insert(string word) {
    TrieNode *node = m_root;

    for (auto c : word) {
      int idx = c - 'a';
      if (node->children[idx] == nullptr) {
        node->children[idx] = new TrieNode;
      }
      node = node->children[idx];
    }

    node->is_word = true;
  }

  bool search(string word) {
    TrieNode *node = m_root;

    for (auto c : word) {
      int idx = c - 'a';
      if (node->children[idx] == nullptr) {
        return false;
      }
      node = node->children[idx];
    }
    return node->is_word;
  }

  bool startsWith(string prefix) {
    TrieNode *node = m_root;
    for (auto c : prefix) {
      int idx = c - 'a';
      if (node->children[idx] == nullptr) {
        return false;
      }
      node = node->children[idx];
    }

    return true;
  }

private:
  struct TrieNode {
    bool is_word;
    array<TrieNode *, 26> children;

    TrieNode() : is_word(false) { children.fill(nullptr); }
    ~TrieNode() = default;
  };

  TrieNode *m_root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @leet end
