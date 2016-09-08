class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0){return 1;}
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(target >= nums[i]){
                res += combinationSum4(nums, target - nums[i]);
            }
        }
        return res;
    }
};
/*class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> res(target + 1);
        res[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto x : nums) {
                if (i >= x){
                    res[i] += res[i - x];
                }
            }
        }
        return res[target];
    }
};

//mycode, time limit exceed
/*class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        combineSumFinder4(nums, target);
        return res.size();
    }
    
private:
    vector<int> path;
    vector<vector<int>> res;
    
    int combineSumFinder4(vector<int>& nums, int target) {
        
        if(target == 0){
            res.push_back(path);
            return;
        }
        
        for(int i = 0; i < nums.size() && target >= nums[i]; i++){
            path.push_back(nums[i]);
            combineSumFinder4(nums, target - nums[i]);
            path.pop_back();
        }
    }        
    

};