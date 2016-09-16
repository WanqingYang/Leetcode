class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        // find first position >= target
        if (nums.size() == 0) {
            return 0;
        }
        
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = (end - start) / 2 + start;
            if (nums[mid] >= target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (nums[start] >= target) {
            return start;
        }
        if (nums[end] >= target) {
            return end;
        }
        
        return nums.size();
    }
};

/*class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size(), mid;
        while (start < end) {
            mid = start + (end - start) / 2;
            if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }
};

/*class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target) {return mid;}
            else if(target > nums[mid]) {start = mid + 1;}
            else {end = mid - 1;}
        }
        // (1) At this point, low > high. That is, low >= high+1
        // (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
        // (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
        //     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
        return start;
    }
};

//mycode, too trivial
/*class Solution {
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