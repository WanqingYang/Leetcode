class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> paths(n,1);
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(j == 0) {continue;}
                else{
                    paths[j] = paths[j-1] + paths[j];
                }
            }
        }
        return paths[n-1];
    }
};