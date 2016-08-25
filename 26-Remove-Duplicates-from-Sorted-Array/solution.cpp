class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 0;// the number of duplicate elements
        for(int i = 1; i < n; i++){//start from 1, compare[0], [1]
            if(nums[i - 1] ==  nums[i]){
                count ++;  //do not need to do change nums, until next non duplicate number appears
            }else{
                nums[i - count] = nums[i];
            }
        }
        return n - count;
    }
};