class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        
        while(start + 1 < end){
            int mid = start + (end - start)/2;
            if(target == nums[mid]){return mid;}
            
            if(nums[mid] >= nums[start]){
                if(target >= nums[start] && target < nums[mid]){
                    end = mid;
                }else{
                    start = mid;
                }
            }
            
            if(nums[mid] <= nums[end]){
                if(target > nums[mid] && target <= nums[end]){
                    start = mid;
                }else{
                    end = mid;
                }
            }
        }
        if(nums[start] == target){
            return start;
        }
        if(nums[end] == target){
            return end;
        }
        return -1;
    }
};