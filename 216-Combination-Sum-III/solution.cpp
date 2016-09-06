class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        //if(n == 0){return res;}
        path.resize(k);
        combineSumFinder3(k, n, 1);
        return res;
    }
    
private:
    vector<int> path;
    vector<vector<int>> res;
    
    void combineSumFinder3(int k, int target, int begin){
        if(k == 0){
            if(target == 0){
                res.push_back(path);
            }
            return;
        }
        
        for(int i = begin; i <= 9 && target >= i; i++){
            path[path.size() - k] = i;
            combineSumFinder3(k - 1, target - i, i + 1);
        }
    }
};