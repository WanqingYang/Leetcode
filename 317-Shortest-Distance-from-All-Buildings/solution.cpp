class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto total = grid;
        int walk = 0, minDis, delta[] = {0, 1, 0, -1, 0};
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    minDis = -1;
                    auto dist = grid;
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    
                    while(!q.empty()) {
                        auto idx = q.front();
                        q.pop();
                        for(int d = 0; d < 4; d++) {
                            int row = idx.first + delta[d];
                            int col = idx.second + delta[d + 1];
                            if(row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == walk) {
                                grid[row][col]--;
                                dist[row][col] = dist[idx.first][idx.second] + 1;
                                total[row][col] += dist[row][col] - 1;//do not forget cummulate
                                q.emplace(row, col);
                                if(minDis < 0 || minDis > total[row][col]) {
                                    minDis = total[row][col];
                                }
                            }
                        }
                    }
                    walk--;
                }
            }
        }
        return minDis;
    }
};