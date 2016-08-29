class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> total;
        int n = nums.size();
        if(n<4)  return total;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return total;
    }
};

/*class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 4 || nums[0] * 4 > target || nums[n - 1] * 4 < target){return res;}
        
        for(int i = 0; i < n - 3; i ++){
            int threeSum = target - nums[i];
            if(3 * nums[i + 1] > threeSum){return res;}
            
            for(int j = i + 1; j < n - 2; j ++){
                int twoSum = threeSum - nums[j];
                if(2 * nums[j + 1] > twoSum){return res;}//think about if more
                int front = j + 1;
                int back = n - 1;
                
                while(front < back){
                    int sum = nums[front] + nums[back];
                    if(sum < twoSum){
                        front ++;
                    }else if(sum > twoSum){
                        back --;
                    }else{
                        vector<int> quadruplet (4, 0);
                        quadruplet[0] = nums[i], quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front], quadruplet[3] = nums[back];
                        res.push_back(quadruplet);
                        
                        while(front < back && nums[front] == quadruplet[2]){front++;}
                        while(front < back && nums[back] == quadruplet[3]){back--;}
                    }
                }
                while(j + 1 < n - 2 && nums[j + 1] == nums[j]){j ++;}
            }
            while(i + 1 < n - 3 && nums[i + 1] == nums[i]){i ++;}
        }
        return res;
    }
};