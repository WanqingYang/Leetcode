/**
 * F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1];
 * F(k-1) = 0 * Bk-1[0] + 1 * Bk-1[1] + ... + (n-1) * Bk-1[n-1]
 *        = 0 * Bk[1] + 1 * Bk[2] + ... + (n-2) * Bk[n-1] + (n-1) * Bk[0];
 * F(k) - F(k-1) = (B[0]+B[1]+...+B[n-1]) - nBk[0];
 * 
 * thus: F(k) = F(k-1) + sum - nBk[0];
 * 
 * Let's find Bk[0]
 * k = 0, Bk[0] = A[0];
 * k = 1, Bk[0] = A[n-1];
 * k = 2, Bk[0] = A[n-2];
 * ...
 * k = n-2, Bk[0] = A[2];
 * k = n-1, Bk[0] = A[1]
 * ...
 * 
 **/

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size(), sum = 0, F = 0;
        for(int i = 0; i < n; i++) {
            F += i * A[i];
            sum += A[i];
        }
        int maxVal = F;
        //cout << "F = " << F << endl;
        for(int i = n-1; i > 0; i--) {
            F = F + sum - n * A[i];
            //cout << "F = " << F << endl;
            maxVal = max(maxVal, F);
        }
        return maxVal;
    }
};