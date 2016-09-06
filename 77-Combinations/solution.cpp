class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> res;
        combineFinder(n, k, 1, path, res);
        return res;
    }
    
    void combineFinder(int n, int k, int begin, vector<int> &path, vector<vector<int>> &res){
        if(k == 0){
            res.push_back(path);
            return;
        }
        
        for(int i = begin; i <= n; i++){
            path.push_back(i);
            k--;
            combineFinder(n, k, i + 1, path, res);
            path.pop_back();
            k++;
        }
    }
};