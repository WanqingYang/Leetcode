class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res; //store the max ele of every increasing subsequence so far
        
        for(int num: nums) {
            auto it = lower_bound(res.begin(), res.end(), num);
            if(it == res.end()) {res.push_back(num);} //num is the largest in res
            else{*it = num;} //replace the lower_bound with num
        }
        return res.size();
    }
};