/**Looking at subarray with index [start,end]. We can find out that if the first member is less than the last member, there's no rotation in the array. So we could directly return the first element in this subarray.

If the first element is larger than the last one, then we compute the element in the middle, and compare it with the first element. If value of the element in the middle is larger than the first element, we know the rotation is at the second half of this array. Else, it is in the first half in the array.
 **/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        
        while(start + 1 < end){
            /*if(nums[start] <= nums[end]){//????
                return nums[start];
            }*/
            
            int mid = start + (end - start)/2;
            if(nums[mid] >= nums[end]){
                start = mid;//must not in the index from start to mid
            }else{
                end = mid;
            }
        }
        return nums[start] <= nums[end]? nums[start] : nums[end];

        //return nums[start];
    }
};