class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while(i < j && !isalnum(s[i])) {i++;}
            while(j > i && !isalnum(s[j])) {j--;}
            if(tolower(s[i]) != tolower(s[j])) {return false;}
        }
        return true;
    }
};
/*class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) {return true;}
        int i = 0, j = s.size() - 1;
        while(i < j) {
            while(i < j && !((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))) {
                i++;
            }
            if(i < j && ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))) { //s[i] ~ a-Z               
                while(j > i && !((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9'))) {
                    j--;
                }
                if(j > i && ((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9'))) { //s[j] ~ a-Z
                    if(tolower(s[i]) != tolower(s[j])) {return false;}
                }
            }
            i++, j--;
        }
        return true;
    }
};