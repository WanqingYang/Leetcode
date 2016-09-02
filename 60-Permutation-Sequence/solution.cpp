class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n + 1, 1);
        vector<int> nums(n);//vector<int> nums(n, 0);
        string res(n,'0');
        //string res;
        
        int fac = 1;
        //create vector of factorial = {1,1,2,6,24,120...,n!}
        for(int i = 1; i <= n; i++){
            fac *= i;
            factorial[i] = fac;
        }
        //create vector of nums = {1,2,3....n}
        for(int j = 0; j < n; j++){
            nums[j] = j + 1;
        }
        
        k--; // do not forget!!!!!
        for(int p = 1; p <= n; p++){
            int index = k / factorial[n - p];
            string tmp = to_string(nums[index]); //get the num
            res.replace(p - 1, 1, tmp);          //replace with num
            //res.append(tmp);
            nums.erase(nums.begin() + index);
            k -= index * factorial[n - p];
        }
        return res;
    }
};