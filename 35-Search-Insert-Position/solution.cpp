class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(target < nums[0]) {return 0;}
        if(target > nums[n - 1]) {return n;}
        
        int start = 0, end = n - 1;
        while(start < end) {
            if(start + 1 == end && target > nums[start] && target < nums[end]) {
                return end;
            }
            
            int mid = start + (end - start) / 2;
            if(target > nums[mid]) {
                start = mid + 1;
            }else{
                end = mid;
            }
        }
        return start;
    }
};