class TrieNode {
    //int prefixCnt;
public:
    // Initialize your data structure here.
    bool isLeaf;
    TrieNode *next[26];
    TrieNode() {
        //prefixCnt = 0;
        isLeaf = false;
        next;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        /*if(search(word)) {return;}
        int i = 0;
        while(startsWith(word.substr(0,i+1))) {
            i++;
        }
        for(; i < word.size(); i++) {
            int idx = word[i] - 'a';
            root->next[idx] = new TrieNode();
            root = root->next[idx];
        }
        root->isLeaf = true;*/
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
       /* for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(!root->next[idx]) {//null, not exist
                return false;
            }
            root = root->next[idx];
        }
        return root->isLeaf;*/
        TrieNode* p = find(word);
        return p != NULL && p->isLeaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        /*for(int i = 0; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';
            if(!root->next[idx]) {//null, not exist
                return false;
            }
            root = root->next[idx];
        }
        return true;  */
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