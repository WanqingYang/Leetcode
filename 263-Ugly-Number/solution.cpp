//i = 4, makes the progress faster
class Solution {
public:
    bool isUgly(int num) {
        for(int i = 2; i < 6 && num; i++) {
            while(num % i == 0) {
                num /= i;
            }
        }
        return num == 1;
    }
};

/*class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) {return false;}
        
        while(num % 2 == 0 || num % 3 == 0 || num % 5 == 0) {
            num = num % 2 == 0? num / 2: num;
            num = num % 3 == 0? num / 3: num;
            num = num % 5 == 0? num / 5: num;
        }
        return num == 1;
    }
};