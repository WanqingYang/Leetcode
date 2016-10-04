//how about this solution??
class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, i = 0;
        long num = 0;
        while(str[i] == ' ') {i++;}
        if(str[i] == '-' || str[i] == '+') {
            sign = 1 - 2 *(str[i++] == '-');
        }
        
        while(isdigit(str[i])) {
            num = num * 10 + (str[i] -'0');
            if(num > INT_MAX || num - 1 >= INT_MAX) {
                if(sign == 1) {return INT_MAX;}
                if(sign == -1) {return INT_MIN;}
            }
            i++;
        }
        return sign *num;
    }
};

/*int atoi(const char *str) {
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }
    if (str[i] == '-' || str[i] == '+') {
        sign = 1 - 2 * (str[i++] == '-'); 
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        base  = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}

/*class Solution {
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