class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = 1; i <= n; ++i){
            for (int j = i - 1; j >= 1; --j){
                int min_value = INT_MAX;
                for (int k = j; k <= i; ++k){
                    int tmp = k + max(dp[j][k - 1], dp[k + 1][i]);
                    min_value = min(min_value, tmp);
                }
                dp[j][i] = min_value;
            }
        }
        return dp[1][n];
    }
};

/*
//mycode, think too easy
class Solution {
public:
    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;
        
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            
            if()
        }
    }
};