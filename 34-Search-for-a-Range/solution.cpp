//two binary search
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        
        //find the left bound
        int start = 0, end = nums.size() - 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(target > nums[mid]) {
                start = mid + 1;
            }else {
                end = mid;
            }
        }
        if(nums[start] == target) {res[0] = start;}
        else {return res;}
        
        //find the right bound
        end = nums.size() - 1; //don't have to set start = 0 again
        while(start < end) {
            int mid = start + (end - start) / 2 + 1; //make mid biased to the right
            if(target < nums[mid]) {
                end = mid - 1;
            }else {
                start = mid;
            }
        }
        res[1] = end;
        return res;
    }
};

//mycode; not thinking completely
/*class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = -1, higher = -1;
        vector<int> res(2, -1);
        int start = 0;
        int end = nums.size() - 1;
        
        while(start < end) {
            int mid = start + (end - start) / 2;
            
            if(target == nums[mid]) {
                lower = higher = mid;
                while(lower - 1 >= 0 && nums[lower - 1] == target){
                    lower--;
                }
                while(higher + 1 < nums.size() && nums[higher + 1] == target){
                    higher++;
                }
                res[0] = lower, res[1] = higher;
                return res;
            }
            
            if(target >= nums[start] && target < nums[mid]) {
                end = mid - 1;
            }
            
            if(target > nums[mid] && target <= nums[end]) {
                start = mid + 1;
            }
        }
        return res;
    }
};