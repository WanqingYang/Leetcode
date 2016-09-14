class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) {return false;}
        int row = matrix.size();
        int col = matrix[0].size();
       // vector<int> start(2, 0);
        //vector<int> end = {row - 1, col - 1};
        int start = 0;
        int end = row * col - 1;
        
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(matrix[mid / col][mid % col] < target) {
                start = mid + 1;
            }else {
                end = mid;
            }
        }
        return matrix[start / col][start % col] == target;
    }
};