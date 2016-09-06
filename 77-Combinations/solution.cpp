/*class Solution {
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
};*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        path.resize(k);
        combineFinder(n, k, 1);
        return res;
    }

private:
    vector<int> path;
    vector<vector<int>> res;
    
    void combineFinder(int n, int k, int begin){
        if(k == 0){
            res.push_back(path);
            return;
        }
        
        for(int i = begin; i <= n; i++){
            path[path.size() - k] = i; //avoid push_back
            combineFinder(n, k - 1, i + 1);
            //path.pop_back();
        }
    }
};