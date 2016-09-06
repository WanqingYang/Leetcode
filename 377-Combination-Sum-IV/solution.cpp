class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (i < num) break;
                dp[i] += dp[i - num];
            }
        }
        return dp.back();
    }
};

/*class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        combineSumFinder4(nums, target);
        return res.size();
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        if(target == 0){
            res.push_back(path);
            return;
        }
        
        for(int i = 0; i < nums.size() && target >= nums[i]; i++){
            path.push_back(nums[i]);
            combinationSum4(nums, target - nums[i]);
            path.pop_back();
        }
    }    
    
private:
    vector<int> path;
    vector<vector<int>> res;
    

};