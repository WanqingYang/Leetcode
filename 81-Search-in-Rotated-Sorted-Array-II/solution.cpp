/**similar to  Find Minimum in Rotated Sorted Array II:
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 * and Search in Rotated Sorted Array: https://leetcode.com/problems/search-in-rotated-sorted-array/
 **/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        
        while(start + 1 < end){
            int mid = start + (end - start) / 2;
            if(nums[mid] == target){return true;}
            
            if(nums[mid] > nums[end]){
                if(target >= nums[start] && target < nums[mid]){
                    end = mid;
                }else{
                    start = mid;
                }
            }else if(nums[mid] < nums[end]){
                if(target > nums[mid] && target <= nums[end]){
                    start = mid;
                }else{
                    end = mid;
                }
            }else{//==
                end--;
            }
        }
        return nums[start] == target || nums[end] == target? true: false;
    }
};