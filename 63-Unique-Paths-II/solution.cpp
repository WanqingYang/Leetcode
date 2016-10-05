class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> paths(n,0);
        for(int j = 0; j < n; j++) {
            if(obstacleGrid[0][j] == 0) {
                paths[j] = 1;
            } else {
                break;
            }
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    paths[j] = 0;
                } else if(j == 0) {
                    continue;
                } else {
                    paths[j] = paths[j-1] + paths[j];
                    //cout << "paths[j] = " << paths[j] << endl;
                }
            }
        }
        return paths[n-1];
    }
};