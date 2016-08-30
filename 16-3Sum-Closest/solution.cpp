//https://discuss.leetcode.com/topic/17215/c-solution-o-n-2-using-sort
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 3){return 0;}//less than 3 ele, return 3
        int closest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        
        for(int first = 0; first < n - 2; first ++){
            if(first > 0 && nums[first] == nums[first - 1]){continue;}
            int second = first + 1;
            int third = n - 1;
            
            while(second < third){
                int curSum = nums[first] + nums[second] + nums[third];
                if(curSum == target){return curSum;}
                if(abs(target - curSum) < abs(target - closest)){closest = curSum;}
                if(curSum < target){second++;}
                else{third--;} //curSum > target
            }
        }
        return closest;
    }
};