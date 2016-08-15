 /**For every house k, there are two options: either to rob it (include this house: i) or not rob it (exclude this house: e).
  * --Include this house:
  * i = num[k] + e (money of this house + money robbed excluding the previous house)
  * 
  * --Exclude this house:
  * e = max(i, e) (max of money robbed including the previous house or money robbed excluding the previous house)
  * (note that i and e of the previous step, that's why we use tmp here to store the previous i when calculating e, to make 
  * O(1) space)
  **/
 //mycode; wrong,for it just calculate odd and even(the right code is to divide into include this house or exclude this house)
/*class Solution {
public:
    int rob(vector<int>& nums) {
        int _size = nums.size();
        if(_size == 0){return 0;}
        if(_size == 1){return nums[0];}
        
        int even = 0, odd = 0;
        for(int i = 0; i < _size; i += 2){//even
            even += nums[i];
        }
        for(int j = 1; j < _size; j +=2){//odd
            odd += nums[j];
        }
        return even >= odd? even : odd;
    }
};*/

 /**For every house k, there are two options: either to rob it (include this house: i) or not rob it (exclude this house: e).
  * --Include this house:
  * i = num[k] + e (money of this house + money robbed excluding the previous house)
  * 
  * --Exclude this house:
  * e = max(i, e) (max of money robbed including the previous house or money robbed excluding the previous house)
  * (note that i and e of the previous step, that's why we use tmp here to store the previous i when calculating e, to make 
  * O(1) space)
  **/
class Solution {
public:
    int rob(vector<int>& nums) {
        int in = 0;
        int ex = 0;
        for(int i = 0; i < nums.size(); i++){
            int tmp = in;
            in = nums[i] + ex;
            ex = max(tmp, ex);
        }
        return max(in, ex);
    }
};