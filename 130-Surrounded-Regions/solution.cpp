class Solution {
public:
	void solve(vector<vector<char>>& board) {
	    int i, j;
	    int row = board.size();
	    if(row == 0){return;}
	    int col = board[0].size();
	    
	    for(i = 0; i < row; i++){
	        check(board, i, 0, row, col);
	        if(col > 1){
	            check(board, i, col - 1, row, col);
	        }
	    }
	    for(j = 0; j + 1 < col; j++){
	        check(board, 0, j, row, col);
	        if(row > 1){
	            check(board, row - 1, j, row, col);
	        }
	    }
	    
	    for(i = 0; i < row; i++){
	        for(j = 0; j < col; j++){
	            board[i][j] = board[i][j] == '1'? 'O' : 'X';
	        }
	    }
    }
    
	void check(vector<vector<char> >&board,int i,int j,int row,int col){
	    if(board[i][j] == 'O'){
	        board[i][j] == '1';
	        
	        if(i > 1){check(board, i - 1, j, row, col);}
	        if(j > 1){check(board, i, j - 1, row, col);}
	        if(i < row - 1){check(board, i + 1, j, row, col);}
	        if(j < col - 1){check(board, i, j + 1, row, col);}
	    }
	}
};