class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) {return 0;}
        int result = nums[0], sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i]; //keep adding each int to sum, until sum drop below 0
            result = max(result, sum);
            sum = max(sum, 0);
        }
        return result;
    }
};