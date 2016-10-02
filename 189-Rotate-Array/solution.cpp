class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        //reverse in a range [first,last), 左闭右开
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};