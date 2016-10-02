class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int res;
        for(int num: nums) {
            if(++cnt[num] > nums.size() / 2) {
                res = num;
            }
        }
        return res;
    }
};

//Bit Manipulation

/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int _size = sizeof(nums[0]);
        
    }
};