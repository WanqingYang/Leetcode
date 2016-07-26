/**IDEA:use unordered_map to store array, set second_num = target-first_num, which is i;
 * NOTICE: the second_num is the 1st in return array, 
 * cause you store it first, then find it through the other num.
 * 
 * TIME:O(N)
 **/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> find_index;
        //unsigned int i;
        vector<int> result;
        int fir_num; //first number in nums, find it through i
        
        for(int i = 0; i < nums.size(); i++)
        {
            fir_num = target - nums[i];
            if(find_index.find(fir_num) != find_index.end())
            {
                result.push_back(find_index[fir_num]);
                result.push_back(i);
            }
           find_index[nums[i]] = i; 
        }
        return result;
    }
};