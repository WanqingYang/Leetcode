//like fibonacci
//f[n] = f[n-1] + f[n-2]; cause from f[n-1] or f[n-2] to f[n], the last step is different
class Solution {
public:
    int climbStairs(int n) {
        if(n < 0) {return -1;}
        if(n <= 2) {return n;}
        
        int ways[n];
        ways[0] = 1, ways[1] = 2;
        for(int i = 2; i < n; i++) {
            ways[i] = ways[i-1] + ways[i-2];
        }
        return ways[n-1];
    }
};

//my code, thinking too complicated
/*class Solution {
public:
    int climbStairs(int n) {
        int ways[n+1][n+1];
        for(int i = 0; i < n+1; i++) {
            ways[0][i] = 0;
        }
        for(int i = 1; i < n+1; i++) {
            
        }
    }
};