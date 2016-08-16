class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //int _size = nums.size();
        //if(_size <= 1){return false;}
        
        unordered_map<int, int> myMap;
        for(int i = 0; i < nums.size(); i++){
            if(myMap.find(nums[i]) != myMap.end()){//contains duplicate
                return true;
            }
            myMap[nums[i]] = i;
        }
        return false;
    }
};