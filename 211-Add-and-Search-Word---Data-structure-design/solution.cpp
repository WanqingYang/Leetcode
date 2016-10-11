class TrieNode {
public:
    bool isLeaf;
    TrieNode *next[26];
    TrieNode() {
        isLeaf = false;
        fill_n(next, 26, nullptr);
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
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

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return find(root, word.c_str());
    }
    
private:
    TrieNode *root;
    
    bool find(TrieNode *root, const char* word) {
        TrieNode *cur = root;
        for(int i = 0; word[i] && cur; i++) {
            if(word[i] != '.') {
                int idx = word[i] - 'a';
                cur = cur->next[idx];
            } else if(word[i] == '.') {
                TrieNode *tmp = cur;
                for(int j = 0; j < 26; j++) {
                    cur = tmp->next[j];
                    if(find(cur, word + i + 1)){return true;}
                }
            }
        }
       return cur && cur->isLeaf; 
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");