class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = -1;           //k is the smaller num in later swap
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                k = i;
                break;
            }
        }
        if(k == -1){
            return reverse(nums.begin(), nums.end());
        }
        int l = -1;          //l is the larger num in later swap
        for(int j = n - 1; j > k; j--){
            if(nums[j] > nums[k]){
                l = j;
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());//next permutation is the next larger num
    }
};