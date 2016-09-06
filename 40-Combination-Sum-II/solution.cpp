class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combineSumFinder2(candidates, target, 0);
        return res;
    }

private:
    vector<int> path;
    vector<vector<int>> res;
    void combineSumFinder2(vector<int>& candidates, int target, int begin){
        if(target == 0){
            res.push_back(path);
            return;
        }
        for(int i = begin; i < candidates.size() && target >= candidates[i]; i++){
            if(i == begin || candidates[i] != candidates[i - 1]){  //remove duplicates candidates  
                path.push_back(candidates[i]);
                combineSumFinder2(candidates, target - candidates[i], i + 1);
                path.pop_back();
            }
        }
    }
};