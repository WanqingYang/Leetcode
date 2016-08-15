class Solution {
public:
    int rob(vector<int>& nums) {
        int _size = nums.size();
        if(_size == 0){return 0;}
        if(_size == 1){return nums[0];}
        return max(robHelper(nums, 0, _size - 1), robHelper(nums, 1, _size));
    }
    
    int robHelper(vector<int>& nums, int start, int end){
        int in = 0;
        int ex = 0;
        for(int i = start; i < end; i ++){
            int tmp = in;
            in = nums[i] + ex;
            ex = max(tmp, ex);
        }
        return in >= ex? in : ex;
    }
};