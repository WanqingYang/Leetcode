// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int start = 1;
        int end = n;
        
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            int feedback = guess(mid);
            
            if(feedback == 0) {
                return mid;
            }else if(feedback == -1) {
                end = mid;
            }else {// == 1
                start = mid;
            }
        }
        return guess(start) == 0? start: end;
    }
};