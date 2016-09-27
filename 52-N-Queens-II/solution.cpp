class Solution {
public:
    int totalNQueens(int n) {
        vector<string> path(n,string(n,'.'));
        solveNQueens(n, 0, path);
        return res.size();
    }
private:
    vector<vector<string>> res;
    void solveNQueens(int n, int row, vector<string>& path) {
        if(row == n) {
            res.push_back(path);
            return;
        }
        
        for(int col = 0; col < n; col++) {
            if(noThreats(n, row, col, path)) {
                path[row][col] = 'Q';
                solveNQueens(n, row + 1, path);
                path[row][col] = '.';
            }
        }
    }
    
    bool noThreats(int n, int row, int col, vector<string>& path) {
        //check the same col, if any Q put in different rows
        for(int i = 0; i < row; i++) {
            if(path[i][col] == 'Q') {return false;}
        }
        //check 45 degree diagnal
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(path[i][j] == 'Q') {return false;}
        }
        //check 135 diagnal
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(path[i][j] == 'Q') {return false;}
        }
        return true;
    }
};