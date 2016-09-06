class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        v.resize(k);
        dfs(1, n, k);
        return r;
    }
private:
    vector<vector<int> > r;
    vector<int> v;
    void dfs(int i, int n, int k) {
        while (i <= n) {
            v[v.size() - k] = i++;
            if (k > 1)
                dfs(i, n, k - 1);
            else
                r.push_back(v);
        }
    }
};

/*class Solution {
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