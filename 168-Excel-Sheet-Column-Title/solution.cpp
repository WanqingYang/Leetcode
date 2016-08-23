/*class Solution {
public:
    string convertToTitle(int n) {
        unordered_map<int, string> dict;
        for(int i = 0; i < 26; i++){
            dict[i] = 'A' + i;
        }
        return dict[n];
    }
};*/

/*class Solution {
public:
    string convertToTitle(int n) {
        return n == 0 ? "" : convertToTitle(n / 26) + (char) (--n % 26 + 'A');
    }
};*/

class Solution {
public:
    string convertToTitle(int n){
        string res;
        char tmp;
        while(n){
            n -= 1;
            tmp = n % 26 + 'A';
            res = tmp + res;
            n = n / 26;
        }
        return res;
    }
};
