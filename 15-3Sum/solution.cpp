class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();

        for(int i = 0; i < n; i ++){
            int target = -nums[i];
            int front = i + 1;
            int back = n - 1;
            
            while(front < back){
                int sum = nums[front] + nums[back];
                if(sum < target){
                    front ++;
                }else if(sum > target){
                    back --;
                }else{//  sum == target
                    vector<int> path (3, 0);
                    path[0] = nums[i];
                    path[1] = nums[front];
                    path[2] = nums[back];
                    res.push_back(path);
                    //processing duplicates of Number 2
                    //move the front pointer to the next different number forward
                    while(front < back && nums[front] == path[1]){front ++;}
                    //processing duplicates of Number 3
                    //move the back pointer to the next different number backward
                    while(front < back && nums[back] == path[2]){back --;}
                }
            }
            //processing duplicates of Number 1
            //move the i pointer to the next different number forward
            while(i + 1 < n && nums[i] == nums[i + 1]){ i ++;}
        }
        return res;
    }
};