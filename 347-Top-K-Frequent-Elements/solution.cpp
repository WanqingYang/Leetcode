//unordered_map store num and frequency,
//priority_queue<pair<int,int>> store freuency and num
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> numFre;
        for(int num: nums) {
            numFre[num]++; //how can write like this
        }
        
        priority_queue<pair<int,int>> pq;
        for(auto it = numFre.begin(); it != numFre.end(); it++) {
            pq.push(make_pair(it->second, it->first));
            /*if(pq.size() > numFre.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }*/
        }
        for(int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};