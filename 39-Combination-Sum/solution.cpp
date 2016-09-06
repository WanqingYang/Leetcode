//no repeated numbers in candidates?
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combineSumFinder(candidates, target, 0);
        return res;
    }
    
private:
    vector<int> path;
    vector<vector<int>> res;
    
    void combineSumFinder(vector<int>& candidates, int target, int begin) {
        if(target == 0){
            res.push_back(path);
            return;
        }
        
        unordered_set<int> mySet;//remove duplicates candidates
        for(int i = begin; i < candidates.size() && target >= candidates[i]; i++){
            if(mySet.find(candidates[i]) == mySet.end()){
                path.push_back(candidates[i]);
                mySet.insert(candidates[i]);
                combineSumFinder(candidates, target - candidates[i], i);
                path.pop_back();
            }else{
                continue;
            }
        }
    }
};