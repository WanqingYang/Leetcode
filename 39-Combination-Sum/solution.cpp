//no repeated numbers in candidates?
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> res;
        combineSumFinder(candidates, target, 0, path, res);
        return res;
    }
    
private:
    void combineSumFinder(vector<int>& candidates, int target, int begin, vector<int> &path, 
    vector<vector<int>> &res) {
        if(target == 0){
            res.push_back(path);
            return;
        }
        
        unordered_set<int> mySet;
        for(int i = begin; i < candidates.size() && target >= candidates[i]; i++){
            if(mySet.find(candidates[i]) == mySet.end()){
                path.push_back(candidates[i]);
                mySet.insert(candidates[i]);
                combineSumFinder(candidates, target - candidates[i], i, path, res);
                path.pop_back();
            }else{
                continue;
            }
        }
    }
};