class Solution {
public:
  int totalNQueens(int n) {
    vector<bool> col(n, true);
    vector<bool> anti(2*n-1, true);
    vector<bool> main(2*n-1, true);
    vector<int> row(n, 0);
    int count = 0;
    dfs(0, row, col, main, anti, count);
    return count;
  }
  void dfs(int i, vector<int> &row, vector<bool> &col, vector<bool>& main, vector<bool> &anti, int &count) {
        if (i == row.size()) {
            count++;
            return;
        }
       for (int j = 0; j < col.size(); j++) {
         if (col[j] && main[i+j] && anti[i+col.size()-1-j]) {
             row[i] = j; 
             col[j] = main[i+j] = anti[i+col.size()-1-j] = false;
             dfs(i+1, row, col, main, anti, count);
             col[j] = main[i+j] = anti[i+col.size()-1-j] = true;
      }
    }
  }
};

/*class Solution {
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