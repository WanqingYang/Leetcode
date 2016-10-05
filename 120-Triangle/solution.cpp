//bottom up
/*class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        //vector<int> minSum(n);
        vector<int> minSum(triangle.back()); //push the entire last vector to the new vector
        
        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                minSum[j] = min(minSum[j], minSum[j+1]) + triangle[i][j];
            }
        }
        return minSum[0];
    }
};*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(!n || !triangle[0].size()) {return 0;}
        int sum[n][n];
        sum[0][0] = triangle[0][0];
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i+1; j++) {
                if(j == 0) {
                    sum[i][j] = sum[i-1][j] + triangle[i][j];
                } else if(j == i) {
                    sum[i][j] = sum[i-1][j-1] + triangle[i][j];
                } else {//j val is between 0 and i
                    sum[i][j] = min(sum[i-1][j-1], sum[i-1][j]) + triangle[i][j];//do not forget add tri[i][j]
                }
            }
        }
        int res = INT_MAX;
        for(int j = 0; j < n; j++) {
            res = min(res, sum[n-1][j]);
        }
        return res;
    }
};