class Solution {
public:
    int numDistinct(string s, string t) {
        int sLen = s.size(), tLen = t.size();
        if(sLen == 0 || tLen == 0) {return 0;}
        //int dp[tLen+1][sLen+1];
        vector<vector<int>> dp(tLen+1, vector<int>(sLen+1, 0));
        //the empty string is a subsequence of any string but only 1 time
        for(int i = 0; i <= sLen; i++) {
            dp[0][i] = 1;
        }
        
        for(int i = 0; i < tLen; i++) {
            for(int j = 0; j < sLen; j++) {
                if(t[i] == s[j]) {
                    dp[i+1][j+1] = dp[i][j] + dp[i+1][j];
                } else{
                    dp[i+1][j+1] = dp[i+1][j];
                }
            }
        }
        return dp[tLen][sLen];
    }
};