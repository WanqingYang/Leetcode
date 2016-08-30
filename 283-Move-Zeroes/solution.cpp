class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int reorder = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[reorder++], nums[i]);
            }else{
                
            }
        }
    }
};