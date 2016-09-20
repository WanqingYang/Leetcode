class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i) {
            for(int j = 0; j < board[i].size(); ++ j) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
            }
        }
        
        return true;
    }
};

/*class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() != 9 || board[0].size() != 9) {
            return false;
        }
        //check every row
        for(int i = 0; i < 9; i++) {
            unordered_set<char> row;
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {continue;}
                if(board[i][j] - '1' < 0 || board[i][j] - '9' > 0 || 
                row.find(board[i][j]) != row.end()) {
                    return false;
                }
                //if(board[i][j] == '.') {continue;}
                //row.find(board[i][j]) == row.end()
                row.insert(board[i][j]);
            }
        }
        //check every column
        for(int j = 0; j < 9; j++) {
            unordered_set<char> col;
            for(int i = 0; i < 9; i++) {
                if(board[i][j] == '.') {continue;}
                if(board[i][j] - '1' < 0 || board[i][j] - '9' > 0 || 
                col.find(board[i][j]) != col.end()) {
                    return false;
                }
                col.insert(board[i][j]);
            }
        }
        return true;
    }
};