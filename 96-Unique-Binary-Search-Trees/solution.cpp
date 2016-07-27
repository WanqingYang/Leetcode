class Solution {
public:
    int numTrees(int n){
        vector<int> f(n+1); //initiate v, if not f is empty, next line f[0] is not exist, seg fault
        f[0] = 1, f[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                f[i] += f[j - 1] * f[i - j];
            }
        }
        return f[n];
    }
};

    /*int numTrees(int n) {
        vector<int> f;
        f.push_back(1);
        for (int i = 1; i < n; ++i) {
            int t = 0;
            for (int j = 0; j < i; ++j)
                t += f[j] * f[i-j-1];
            f.push_back(t);
        }
        return f.back();
    }*/
