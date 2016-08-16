class Solution {
private:
    vector<vector<int>> dp; //store the max path in this node
    vector<pair<int, int>> direction; //the left, right, up and down 
    int m, n;
    
    int DFS(vector<vector<int>>& matrix, int &i, int &j){
        if(dp[i][j] != 0){return dp[i][j];}
        int longest = 1;
        for(auto dir : direction){
            int x = i + dir.first, y = j + dir.second;
            if(x < 0 || x >= m || y < 0 || y >=n || matrix[x][y] <= matrix[i][j]){
                continue;
            }else{
                longest = max(longest, DFS(matrix, x, y) + 1);
            }
        }
        dp[i][j] = longest;
        return longest;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()){return 0;}
        m = matrix.size(), n = matrix[0].size();
        direction.push_back(pair<int, int>(1,0));
        direction.push_back(pair<int, int>(-1,0));
        direction.push_back(pair<int, int>(0,1));
        direction.push_back(pair<int, int>(0,-1));
        //initialization of dp
        dp = vector<vector<int>> (m, vector<int> (n,0));
        int longest = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                longest = max(longest, DFS(matrix, i, j));
            }
        }
        return longest;
    }
};