class Solution {
    
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> find_index;
        //unsigned int i;
        vector<int> result;
        int sec_num;
        
        for(int i = 0; i < nums.size(); i++)
        {
            sec_num = target - nums[i];
            if(find_index.find(sec_num) != find_index.end())
            {
                result.push_back(find_index[sec_num]);
                result.push_back(i);
            }
           find_index[nums[i]] = i; 
        }
        return result;
    }
};