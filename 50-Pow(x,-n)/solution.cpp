//double x
/*class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) {return 1;}
        if(n < 0) {
            x = 1/x;
            n = -n;
        }
        return n % 2 == 0? myPow(x*x, n/2): x*myPow(x*x, n/2);
    }
};*/

//double myPow
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) {return 1;}
        double tmp = myPow(x, n/2);
        if(n % 2) {
            return n < 0? 1/x*tmp*tmp : x*tmp*tmp;
        } else {
            return tmp*tmp;
        }
    }
};

