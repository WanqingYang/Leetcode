class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        if(n == 0) {return 0;}
        
        long num = 0; //deal with overflow
        for(int i = 0; i < n; i++) {
            if(str[i] == ' ') {
                if(i == 0 || str[i-1] == ' ') {continue;}
            }
            
            if(str[i] == '-') {
                if(i == 0 || str[i-1] == ' ') {
                    while(i < n) {
                        i++;
                        if(isdigit(str[i])) {
                            num = num * 10 + (str[i] - '0');
                            if(num - 1 >= INT_MAX) {return INT_MIN;}
                        } else {
                            return -num;
                        }
                    }
                    return -num;
                }
            }
            if(str[i] == '+') {
                if(i == 0 || str[i-1] == ' ') {continue;}
            }

            if(isdigit(str[i])) {
                int b = str[i] - '0';
                num = num * 10 + b;
                if(num > INT_MAX) {return INT_MAX;}
            } else {
                return num;
            }
        }
        return num;
    }
};