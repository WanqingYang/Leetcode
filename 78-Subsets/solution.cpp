class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        findSubsets(nums, 0);
        return res;
    }
    
private:
    vector<vector<int>> res;
    vector<int> path;
    
    void findSubsets(vector<int>& nums, int start) {
        //path.push_back;
        res.push_back(path);
        
        for(int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            findSubsets(nums, i + 1);
            path.pop_back();
        }
    }
};