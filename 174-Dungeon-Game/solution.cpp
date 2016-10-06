//2D dp
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> hp(m+1, vector<int>(n+1, INT_MAX));
        hp[m][n-1] = hp[m-1][n] = 1;
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                int need = min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j];
                hp[i][j] = need <= 0? 1: need;
            }
        }
        return hp[0][0];
    }
};

//mycode too complicated
/*class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<int> minHP(n,dungeon[0][0]); //what is the cumulation now
        vector<int> minSoFar(n, dungeon[0][0]);//smallest num sofar
        for(int j = 1; j < n; j++) {
            minHP[j] = minHP[j-1] + dungeon[0][j];
            minSoFar[j] = min(minSoFar[j-1], minHP[j]);
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(j == 0) {
                    minHP[j] = minHP[j] + dungeon[i][j];
                    minSoFar[j] = min(minSoFar[j] + dungeon[i][j], minHP[j]);
                    //minSoFar[j] = min(minSoFar[j], minHP[j]);
                }else if(dungeon[i][j] < 0) {
                    minHP[j] = max(minHP[j], minHP[j-1]) + dungeon[i][j];
                    minSoFar[j] = min(max(minSoFar[j-1], minSoFar[j]), minHP[j]);
                } else{ // > 0
                    minHP[j] = max(minHP[j], minHP[j-1]) + dungeon[i][j];
                    minSoFar[j] = max(minSoFar[j-1], minSoFar[j]);
                    if(minSoFar[j] > 0) {
                        minSoFar[j] += dungeon[i][j];
                    }
                }
                
            }
        }
        return minSoFar[n-1] < 0? -minSoFar[n-1] + 1: 1;
    }
};