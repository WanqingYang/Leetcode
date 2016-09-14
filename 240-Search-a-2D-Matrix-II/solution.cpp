class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0) {return false;}
        int col = matrix[0].size();
        if(col == 0) {return false;}
        
        int i = 0, j = col - 1;
        while(i < row && j >= 0) {
            if(matrix[i][j] < target) {
                i++;
            }else if(matrix[i][j] > target) {
                j--;
            }else {
                return true;
            }
        }
        return false;
    }
};
//mycode too complicated
/*class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0) {return false;}
        int col = matrix[0].size();
        if(col == 0) {return false;}
        
        vector<int> start(2,0);
        vector<int> end = {row - 1, col - 1};
        
        while(start[0] < end[0] && start[1] < end[1]) {
            int first = start[0] + (end[0] - start[0]) / 2;
            int second = start[1] +  (end[1] - start[1]) / 2;
            vector<int> mid = {first, second};
            if(target > matrix[mid[0]][mid[1]]) {
                start[0] = mid[0] + 1;
                start[1] = mid[1] + 1;
            }else {
                end[0] = mid[0];
                end[1] = mid[1];
            }
        }
        return matrix[start[0]][start[1]] == target;
    }
};