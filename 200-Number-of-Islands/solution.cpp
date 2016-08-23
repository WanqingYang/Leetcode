class Solution {
private: int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        m = grid.size();
        if(m == 0){return 0;}
        n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){ //once '1' visited, there must be an island
                    DFSMarking(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }
    
    void DFSMarking(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1'){return;}
        grid[i][j] = '0'; //mark the '1' to '0' as marked(visited)
        DFSMarking(grid, i + 1, j);
        DFSMarking(grid, i - 1, j);
        DFSMarking(grid, i, j + 1);
        DFSMarking(grid, i, j - 1);
    }
};