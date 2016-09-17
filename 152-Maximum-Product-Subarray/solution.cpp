class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0], imax = nums[0], imin = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0) {
                swap(imax, imin);
            }
            
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);
            
            result = max(result, imax);
        }
        return result;
    }
};

/*int maxProduct(int A[], int n) {
    // store the result that is the max we have found so far
    int r = A[0];

    // imax/imin stores the max/min product of
    // subarray that ends with the current number A[i]
    for (int i = 1, imax = r, imin = r; i < n; i++) {
        // multiplied by a negative makes big number smaller, small number bigger
        // so we redefine the extremums by swapping them
        if (A[i] < 0)
            swap(imax, imin);

        // max/min product for the current number is either the current number itself
        // or the max/min by the previous number times the current one
        imax = max(A[i], imax * A[i]);
        imin = min(A[i], imin * A[i]);

        // the newly computed max value is a candidate for our global result
        r = max(r, imax);
    }
    return r;
}


//mycode, wrong
/*class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> zeroIndex;
        int zeroCache = nums[0];
        int minusCache = nums[0];
        //int traverse;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                result *= nums[i];
            }else if(nums[i] < 0) {
                
                if(minusCache < 0) {
                    result = minusCache * result * nums[i];
                    minusCache = result;
                }else if(minusCache > 0) {
                    minusCache = 
                } 
                
            }else { //== 0
                zeroCache = max(zeroCache, result);
                if(i + 1 < nums.size()) {
                    result = nums[i + 1];
                }
            }
        }
    }
};