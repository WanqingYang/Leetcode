//greedy
/*class Solution {
public:
    int jump(vector<int>& nums) {
        
    }
};*/

//dp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        cout << "nums size is " << n << endl;
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= nums[0]; i++) {
            dp[i] = 1;
            if(i == n-1) {
                return 1;
            }
        }
        //cout << "pass the first for loop" << endl;
        for(int i = 1; i < n; i++) {
            //cout << "i = " << i << endl;
            int minStep = dp[i] + 1;
            for(int j = 1; j <= nums[i]; j++) {
                //cout << "i+j = " << i+j << endl;
                dp[i+j] = min(dp[i+j], minStep);
                if(i+j == n-1) {
                    return dp[n-1];
                }
            }
        }
        //cout << "pass the 2nd for loop" << endl;
        return dp[n-1];
    }
};
/*class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i < n && i <= nums[0]; i++) {
            dp[i] = 1;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; i+j < n && j <= nums[i]; j++) {
                dp[i+j] = min(dp[i+j], dp[i] + 1);
            }
        }
        return dp[n-1];
    }
};