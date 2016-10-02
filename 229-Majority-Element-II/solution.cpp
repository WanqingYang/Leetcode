//Boyer-Moore Majority Vote algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if(n == 0) {return res;}
        //find the majority 2 nums
        int major1 = 0, cnt1 = 0, major2 = 1, cnt2 = 0;
        for(int num: nums) {
            if(num == major1) {
                cnt1++;
            } else if(num == major2) {
                cnt2++;
            } else if(cnt1 == 0) {
                major1 = num;
                cnt1++;
            } else if(cnt2 == 0) {
                major2 = num;
                cnt2++;
            } else{
                cnt1--, cnt2--;
            }
        }
        //check if > n/3
        cnt1 = cnt2 = 0;
        for(int num: nums) {
            if(num == major1) {cnt1++;}
            if(num == major2) {cnt2++;}
        }
        //cout<< "major1 = " << major1 << ", major2 = " << major2 << endl;
        //cout<< "cnt1 = " << cnt1 << ", cnt2 = " << cnt2 << endl;
        if(cnt1 > n/3) {res.push_back(major1);}
        if(cnt2 > n/3) {res.push_back(major2);}
        return res;
    }
};