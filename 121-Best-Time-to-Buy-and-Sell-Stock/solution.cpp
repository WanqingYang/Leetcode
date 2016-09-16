class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
        if(prices.empty()) {
            return 0;
        }
        int result = 0;
        int minPrice = INT_MAX;
        
        for(int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            result = max(result, prices[i] - minPrice);
        }
        return result;
    }
};