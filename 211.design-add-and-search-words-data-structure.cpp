// @leet start
#include <array>
#include <string>
using namespace std;

class WordDictionary {
public:
  WordDictionary() { m_root = new TrieNode(); }

  void addWord(string word) {
    TrieNode *curr = m_root;
    for (auto c : word) {
      int idx = c - 'a';
      if (curr->children[idx] == nullptr) {
        curr->children[idx] = new TrieNode();
      }
      curr = curr->children[idx];
    }
    curr->last_of_word = true;
  }

  bool search(string word) { return recursive_search(word, 0, m_root); }

private:
  struct TrieNode {
    bool last_of_word;
    array<TrieNode *, 26> children;

    TrieNode() : last_of_word(false), children({}) {}
  };

  TrieNode *m_root;

  bool recursive_search(const string &word, int pos, TrieNode *node) {
    if (pos == word.size()) {
      return node->last_of_word;
    }

    if (word[pos] != '.') {
      node = node->children[word[pos] - 'a'];
      return node ? recursive_search(word, pos + 1, node) : false;
    }
    for (int i = 0; i < 26; i++) {
      if (node->children[i] != nullptr &&
          recursive_search(word, pos + 1, node->children[i])) {
        return true;
      }
    }
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @leet end
