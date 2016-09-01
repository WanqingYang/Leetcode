class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        permute(nums, 0, res);
        return vector<vector<int>> (res.begin(), res.end());
    }
    void permute(vector<int> &nums, int start, set<vector<int>> &res) {
        if (start >= nums.size()) res.insert(nums);
        for (int i = start; i < nums.size(); ++i) {
            if (i != start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]);
            permute(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }
};
/*class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        permuteRecursion(nums, 0, tmp, res);
        return res;
    }
    
    void permuteRecursion(vector<int> &nums, int begin, vector<int> &tmp, vector<vector<int>> &res){
        if(begin == nums.size()){
            res.push_back(tmp);
            return;
        }
       
        unordered_set<int> mySet;
        for(int i = begin; i < nums.size(); i++){
            if(mySet.find(i) == mySet.end()){
                mySet.insert(nums[i]);
                swap(nums[begin], nums[i]);
                tmp.push_back(nums[begin]);
                permuteRecursion(nums, begin + 1, tmp, res);
                tmp.pop_back();
                swap(nums[begin], nums[i]);// reset, backtracking
            }
        }
    }
};