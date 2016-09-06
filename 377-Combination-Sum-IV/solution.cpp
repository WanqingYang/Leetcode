
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        combineSumFinder4(nums, target);
        return res.size();
    }
    
private:
    vector<int> path;
    vector<vector<int>> res;
    
    void combineSumFinder4(vector<int>& nums, int target) {
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