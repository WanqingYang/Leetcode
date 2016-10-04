class TrieNode {
    //int prefixCnt;
public:
    // Initialize your data structure here.
    bool isLeaf;
    TrieNode *next[26];
    TrieNode() {
        //prefixCnt = 0;
        isLeaf = false;
        fill_n(next, 26, nullptr);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(!cur->next[idx]) {
                cur->next[idx] = new TrieNode();
            }
            cur = cur->next[idx];
        }
        cur->isLeaf = true;
        return;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = find(word);
        return p != NULL && p->isLeaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return find(prefix) != NULL;
    }

private:
    TrieNode* root;
    
    TrieNode* find(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size() && cur != NULL; i++) {
            int idx = word[i] - 'a';
            cur = cur->next[idx];
        }
        return cur;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");