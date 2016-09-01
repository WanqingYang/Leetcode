class Solution {
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
            if(mySet.find(nums[i]) == mySet.end()){
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

/*class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> out;
        vector<int> visited(num.size(), 0);
        sort(num.begin(), num.end());
        permuteUniqueDFS(num, 0, visited, out, res);
        return res;
    }
    void permuteUniqueDFS(vector<int> &num, int level, vector<int> &visited, vector<int> &out, vector<vector<int> > &res) {
        if (level >= num.size()) res.push_back(out);
        else {
            for (int i = 0; i < num.size(); ++i) {
                if (visited[i] == 0) {
                    if (i > 0 && num[i] == num[i - 1] && visited[i - 1] == 0) continue;
                    visited[i] = 1;
                    out.push_back(num[i]);
                    permuteUniqueDFS(num, level + 1, visited, out, res);
                    out.pop_back();
                    visited[i] = 0;
                }
            }
        }
    }
};

/*class Solution {
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