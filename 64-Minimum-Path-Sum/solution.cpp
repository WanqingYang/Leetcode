//top down
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        
        vector<int> minSum(col,grid[0][0]);
        for(int j = 1; j < col; j++) {
            minSum[j] = minSum[j-1] + grid[0][j];
        }

        for(int i = 1; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(j == 0) {
                    minSum[j] = minSum[j] + grid[i][j];
                } else {
                    minSum[j] = min(minSum[j], minSum[j-1]) + grid[i][j];
                }
            }
        }
        return minSum[col-1];
    }
};