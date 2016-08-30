/*class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i ++){
            if(nums[i] == val){
                cnt++;
            }else{
                nums[i - cnt] = nums[i];
            }
        }
        return n - cnt;
    }
};*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[res++] = nums[i];
            }
        }
        return res;
    }
};

