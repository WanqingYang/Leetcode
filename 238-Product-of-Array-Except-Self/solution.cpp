/**reserve the vector of int with value 1 and size n;
 * in the for loop from i to n - 1, update the result vector:
 * int fromBeigin is the products from 0 to n-1;
 * int fromLast is the producs from n-1 to 0
 * result update 2n times, finally get the answer
 **/
//http://fisherlei.blogspot.com/2015/10/leetcode-product-of-array-except-self.html
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int fromBegin = 1;
        int fromLast = 1;
        vector<int> res (n, 1);  //reserve size
        
        for(int i = 0; i < n; i ++){
            res[i] *= fromBegin;
            fromBegin *= nums[i];
            res[n - 1 - i] *= fromLast;
            fromLast *= nums[n - 1 - i];
        }
        return res;
    }
};