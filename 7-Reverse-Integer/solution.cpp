class Solution {
public:
    int reverse(int x) {
        //int result = 0;
        long result = 0;
        //long long result = 0; //long long make res a 64 bit number, the overflow is checked.
        while(x != 0){
            result = result * 10 + x % 10;
            x = x/10;
        }
        return (result < INT_MIN || result > INT_MAX) ? 0: result;
    }
};
    
/*  int result = 0;

    while (x != 0)
    {
        int tail = x % 10;
        int newResult = result * 10 + tail;
        if ((newResult - tail) / 10 != result)
        { return 0; }
        result = newResult;
        x = x / 10;
    }
}
    return result;
};*/

/*class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};

