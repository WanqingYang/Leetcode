class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> path(n,string(n,'.'));
        solveNQueens(n, 0, path);
        return res;
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
/*class Solution {
    vector<int> path(n,-2);
    //vector<int> path;
    vector<vector<int>> positions;
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        //vector<string> row(n,".");
        //vector<vector<string>> chessBoard(n,row);
        //vector<vector<int>> position = putQueens(n);
        putQueens(n);
        drawQueens(positions);
        return res;
    }
    
    void drawQueens(vector<vector<int>> &position) {
        
    }
    
    bool noThreat(vector<int> &check) {
        
    }
    
    //vector<vector<int>> putQueens(int n) {
    void putQueens(int n) {
        for(int i = 0; i < n; i++) { //every row
            
            for(int j = 0; j < n; j++) {//which column
                //chessBoard[i][j] = "Q";
                path[i] = j; 
                if(noThreat(path)) {
                    break;
                } else {
                    path[i] = -2;
                }
            }
            //if(path[i] == -2) {return 
            //if no solution, no push
            if(i == n - 1 && path[i] >= 0) {positions.push_back(path);}
        }
        //return positions;
    }
};