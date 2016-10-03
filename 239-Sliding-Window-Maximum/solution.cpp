class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) {return vector<int>();}
        vector<int> res(n-k+1);
        deque<int> dq;//
        for(int i = 0; i < k; i++) {
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        for(int i = k; i < n; i++) {
            //store res[i-k], when it right reach i(i>=k);
            res[i-k] = nums[dq.front()];
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            while(!dq.empty() && dq.front() <= i-k) {
                dq.pop_front();
            }
            dq.push_back(i);
            //res[i-k] = nums[dq.front()];
        }
        //cout<<"jump out of for loop" << endl;
        cout << dq.front();
        res[n-k] = nums[dq.front()];//do not forget this
        return res;
    }
}; 