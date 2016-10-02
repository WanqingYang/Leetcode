/*class Solution {
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
};*/

//Bit Manipulation
/**The key lies in how to count the number of 1's on a specific bit. 
 * You need a mask with a 1 on the i-th bit and 0 otherwise to get the i-th bit of each element in nums.
 **/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int _size = sizeof(nums[0]), major = 0;
        for(int i = 0, mask = 1; i < 32; i++, mask <<= 1) { //mask: the bit I am looking is 1, others all 0
            int cnt = 0;
            for(int num: nums) {
                if(num & mask) {cnt++;}// !0 is true, 0 is false
                if(cnt > nums.size()/2) {// 1 appear times over n/2
                    major |= mask;
                    break;
                }
            }
        }
        return major;
    }
};