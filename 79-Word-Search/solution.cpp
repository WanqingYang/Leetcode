class Solution {
private:
    int row, col, _size;
    bool dfs(vector<vector<char>>& board, string &word, int idx, int i, int j) {
        if(idx == _size) {return true;}
        if(i < 0 || i >= row || j < 0 || j >= col || board[i][j] != word[idx] || board[i][j] == '*'){
            return false;
        }
        //if(idx == _size) {return true;}
        char origin = board[i][j];
        board[i][j] = '*';
        if(dfs(board, word, idx+1, i-1, j) || dfs(board, word, idx+1, i+1, j) || dfs(board, word, idx+1, i, j-1) || 
        dfs(board, word, idx+1, i, j+1)) {return true;}
        board[j][j] = origin;
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        _size = word.size();
        if(!(row = board.size()) || !(col = board[0].size()) || !_size) {return false;}
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(dfs(board, word, 0, i, j)){return true;}
            }
        }
        return false;
    }
};