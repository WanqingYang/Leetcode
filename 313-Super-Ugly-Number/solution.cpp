class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int _size = primes.size();
        vector<int> res(1,1);
        vector<int> cnt(_size, 0);
        vector<int> val(_size, 1);
        
        int minimum = 1;
        //while(res.size() < n) {
        for(int i = 0; i < _size; i++) {
            res[i] = minimum;
            
            minimum = INT_MAX;
            for(int j = 0; j < _size; j++) {
                //skip duplicate and avoid extra multiplication
                if(val[j] == res[i]) {
                    val[j] = res[cnt[j]++] * primes[j];
                }
                minimum = min(minimum, val[j]);
            }
        }
        return res[n-1];
    }
};

/*class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(1,1);
        int _size = primes.size();
        vector<int> cnt(_size, 0);

        int minimum = INT_MAX;
        while(res.size() < n) {
            minimum = res[cnt[0]] * primes[0];
            for(int i = 1; i < _size; i++) {
                minimum = min(minimum, res[cnt[i]] * primes[i]);
            }
            res.push_back(minimum);
            for(int j = 0; j < _size; j++) {
                if(res[cnt[j]] * primes[j] == minimum) {
                    cnt[j]++;
                }
            }
        }
        return res[n-1];
    }
};