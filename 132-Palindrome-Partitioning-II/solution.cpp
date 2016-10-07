class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        //preparation
        vector<vector<bool>> booldp(n, vector<bool>(n, true));
        
        for (int i = 0; i < n; i++) {
            booldp[i][i] = true;
            if (i + 1 < n) {
                booldp[i][i + 1] = (s[i] == s[i + 1]);
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                booldp[i][j] = booldp[i + 1][j - 1] && (s[i] == s[j]);
            }
        }
        
        //initialization
        vector<int> cutdp(n+1);
        cutdp[0] = -1;

        for(int i = 1; i <= n; i++) {
            cutdp[i] = i-1;
            for(int j = 0; j < i; j++) {
                if(booldp[j][i-1]) {
                    cutdp[i] = min(cutdp[i], cutdp[j] + 1);
                }
            }
        }
        return cutdp[n];
    }
};

/*class Solution {
    vector<vector<bool>> isPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> booldp(n, vector<bool>(n, true));
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int a = i, b = j; b > a; a++, b--) {
                    if(s[a] != s[b]) {
                        booldp[i][j] = false;//notbool dp[a][b]!!!
                        break;
                    }
                }
            }
        }
        return booldp;
    };
    
public:
    int minCut(string s) {
        int n = s.size();
        //preparation
        vector<vector<bool>> booldp = isPalindrome(s);
        
        //initialization
        vector<int> cutdp(n+1);
        cutdp[0] = -1;

        for(int i = 1; i <= n; i++) {
            cutdp[i] = i-1;
            for(int j = 0; j < i; j++) {
                if(booldp[j][i-1]) {
                    cutdp[i] = min(cutdp[i], cutdp[j] + 1);
                }
            }
        }
        return cutdp[n];
    }
};