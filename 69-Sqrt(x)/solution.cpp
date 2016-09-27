class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) {return 0;}
        int i = 0;
        while(i * i <= x) {
            if(i * i == x) {return i;}
            i++;
        }
        /*for(int i = 0; i * i <= x; i++) {
            if(i * i == x) {return i;}
        }*/
        return i - 1;
    }
};