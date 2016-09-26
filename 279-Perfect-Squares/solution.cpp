//dp tells the numbers of squares needed for the first integers, and when asked about a new n, 
// extend dp just as much as necessary.

class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp {0};
        while(dp.size() <= n) {
            int m = dp.size(), square = INT_MAX;
            for(int i = 1; i * i <= m; i++) {
                square = min(square, dp[m - i * i] + 1);
            }
            dp.push_back(square);
        }
        return dp[n];
    }
};