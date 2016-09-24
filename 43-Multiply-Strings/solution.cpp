class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> pos(m + n, 0);
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = product + pos[p2]; 
                
                pos[p1] += sum / 10; //why not: pos[p1] = sum / 10
                pos[p2] = sum % 10;
            }
        }
        
        string result;
        for(int digit: pos) {
            if(!(result.size() == 0 && digit == 0)) {
                result.append(to_string(digit));
            }
        }
        return result.size() == 0? "0": result;
    }
};