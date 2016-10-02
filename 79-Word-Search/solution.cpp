class Solution {
private:
    //int row, col;
    bool dfs(vector<vector<char>>& board, string &word, int idx, int i, int j) {
        //if(idx == _size) {return true;}
        //cout<<"entering dfs, idx, i, j = "<< idx << i << j << endl;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() /*|| idx >= word.size()*/ || board[i][j] != word[idx] || board[i][j] == '*'){
            //cout << "got here! directly return false, j = " << j << endl;
            return false;
        }
        if(idx == word.size() - 1) {return true;}
        char origin = board[i][j];
        board[i][j] = '*';
        if(dfs(board, word, idx+1, i-1, j) || dfs(board, word, idx+1, i+1, j) || dfs(board, word, idx+1, i, j-1) || 
        dfs(board, word, idx+1, i, j+1)) {return true;}
        //board[j][j] = origin;
        board[i][j] = origin;
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row, col, _size = word.size();
        if(!(row = board.size()) || !(col = board[0].size()) || !_size) {return false;}
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                //cout << "board[i][j] = " << board[i][j] << endl;
                if(dfs(board, word, 0, i, j)){return true;}
            }
        }
        return false;
    }
};