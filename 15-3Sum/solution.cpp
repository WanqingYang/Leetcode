class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 3 || 3 * nums[0] > 0 || 3 * nums[n - 1] < 0){return res;}

        for(int i = 0; i < n - 2; i ++){
            int target = -nums[i];
            int front = i + 1;
            int back = n - 1;
            //if(2*nums[front] > target || 2*nums[back] < target){return res;}
            if(nums[i] > 0 || 2*nums[front] > target){break;}
            if(nums[n - 2] + nums[n - 1] < target){continue;}
            
            while(front < back){
                int sum = nums[front] + nums[back];
                if(sum < target){
                    front ++;
                }else if(sum > target){
                    back --;
                }else{//  sum == target
                    res.push_back(vector<int>{nums[i], nums[front], nums[back]});
                    //processing duplicates of Number 2
                    //move the front pointer to the next different number forward
                    do{front ++;}while(front < back && nums[front] == nums[front - 1]);
                    //processing duplicates of Number 3
                    do{back --;}while(front < back && nums[back] == nums[back + 1]);
                }
            }
            //processing duplicates of Number 1,move the pointer to the next different number forward
            while(i + 1 < n - 2 && nums[i] == nums[i + 1]){ i ++;}
        }
        return res;
    }
};