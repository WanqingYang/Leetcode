//Newton Method
/**my understanding:
 * r^2 = x;
 * r = x/r
 * 2r = r + x/r
 * r = (r + x/r) /2
**/
class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        while(r * r > x) {
            r = (r + x/r) / 2;
        }
        return r;
    }
};