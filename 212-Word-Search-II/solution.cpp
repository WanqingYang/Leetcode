/*class Solution {
    
private:
    class Trie {
    public:
        int prefixCnt;
        bool isLeaf;
        int wordIdx;
        Trie* children[26];
    
        Trie() {
            prefixCnt = 0;
            isLeaf = false;
            wordIdx = 0;
            fill_n(children, 26, nullptr);
            //children.fill(NULL);
        }
    
        ~Trie() {
            for(int i = 0; i < 26; i++) {
                delete children[i];//recursive delete all trie
            }
        }
    };

    Trie* buildTrie(vector<string>& words) {
        Trie* root = new Trie();
        for(int i = 0; i < words.size(); i++) {
            insertWord(words[i], root, i);
        }
        return root;
    }
    
    void insertWord(string word, Trie* root, int idx) {
        root->prefixCnt++;
        int chIdx;
        for(int i = 0; i < word.size(); i++) {
            chIdx = word[i] - 'a';
            if(!(root->children[chIdx])) {
                root->children[chIdx] = new Trie();
            }
            root = root->children[chIdx];
            root->prefixCnt++;
        }
        root->isLeaf = true;
        root->wordIdx = idx;//do not forget
    }
    
    vector<string> res;
    int dfs_Trie(vector<vector<char>>& board, vector<string>& words, int i, int j, Trie* root) {
        int validCnt = 0;
        //base case
        if(root->isLeaf) {
            res.push_back(words[root->wordIdx]);
            root->isLeaf = false;
            validCnt++;
            return validCnt;
        }
        
        //int curC = board[i][j] - 'a';
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '*' || 
        !(root->children[board[i][j] - 'a']) || root->children[board[i][j] - 'a']->prefixCnt <= 0) {//why not:  !(root->children[curC]->prefixCnt)
            return validCnt;
        }
        
        int curC = board[i][j] - 'a';
        board[i][j] = '*';
        Trie *child = root->children[curC];
        validCnt += dfs_Trie(board, words, i-1, j, child) + dfs_Trie(board, words, i+1, j, child) + 
        dfs_Trie(board, words, i, j-1, child) + dfs_Trie(board, words, i, j+1, child);
        board[i][j] = 'a' + curC;
        root->prefixCnt -= validCnt;
        return validCnt;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row, col, _size = words.size();
        if(!(row = board.size()) || !(col = board[0].size()) || !_size) {return res;}// !0 == true 
        
        Trie* root = buildTrie(words);
        
        for(int i = 0; i < row && root->prefixCnt; i++) {//???root->prefixCnt
            for(int j = 0; j < col; j++) {
                dfs_Trie(board, words, i, j, root);
            }
        }
        delete root;
        return res;
    }
};*/


class Solution {
private:
class Trie
{
public:    
    Trie * children[26];
    bool isLeaf;
    int  wordIdx;
    int prefixCount;
    
    Trie()
    {
        isLeaf = false;
        wordIdx = 0;
        prefixCount = 0;
        fill_n(children, 26, nullptr);
        //fill(NULL);
    }
    
    ~Trie()
    {
        for(auto i=0; i<26; ++i) delete children[i];
    }
};
    void insertWord(Trie *root,  const vector<string>& words, int idx)
    {
        int i, childID, len = words[idx].size();
        for(i=0, root->prefixCount++; i<len; ++i)
        {
            childID = words[idx][i]-'a';
            if(!root->children[childID]) {root->children[childID] = new Trie();}
            root = root->children[childID];
            ++root->prefixCount;
        }
        root->isLeaf = true; 
        root->wordIdx = idx;
    }
    
    Trie *buildTrie(const vector<string> &words)
    {
        Trie *root = new Trie();
        for(int i=0; i < words.size(); ++i) insertWord(root, words, i);
        return root;
    }
    
    int dfs_Trie(vector<string> &res, Trie *root, vector<vector<char>>& board, vector<string>& words, int row, int col)
    {
        int detected = 0;//an word find

        if(root->isLeaf)
        {
            ++detected;
            root->isLeaf = false;//avoid same word multiple store in res
            res.push_back(words[root->wordIdx]);
        }
        
        if( row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col]=='*' || !root->children[ board[row][col]-'a'] || root->children[ board[row][col]-'a']->prefixCount <= 0 ) return detected;
        
        int curC = board[row][col] - 'a';
        board[row][col] = '*';
        detected += dfs_Trie(res, root->children[curC], board, words, row-1, col) + 
               dfs_Trie(res, root->children[curC], board, words, row+1, col) +    
               dfs_Trie(res, root->children[curC], board, words, row, col - 1) +    
               dfs_Trie(res, root->children[curC], board, words, row, col + 1) ;
        root->prefixCount -=detected;
        board[row][col] = curC+'a';
        return detected;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int M, N, wordNum = words.size();
        vector<string> res;
        if( !(M = board.size()) || !(N = board[0].size()) || !wordNum) return res;
        Trie *root = buildTrie(words);
        for(auto i=0; i<M && root->prefixCount; ++i)
            for(auto j=0; j<N; ++j)
                dfs_Trie(res, root, board, words, i, j);
        delete root;
        return res;
    }
};