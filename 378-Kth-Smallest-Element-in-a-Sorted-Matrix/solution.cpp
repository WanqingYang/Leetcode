/**every time calculate the elements less or equal to mid
 **/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if(n == 0) {return 0;}
        int start = matrix[0][0], end = matrix[n-1][n-1];
        while(start < end) {
            int mid = start + (end - start) / 2;
            int cnt = 0, j = n - 1;
            for(int i = 0; i < n; i++) {
                while(j >=0 && matrix[i][j] > mid) {
                    j--;
                }
                cnt += j+1;
            }
            if(cnt < k) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
};