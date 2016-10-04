class Solution {
public:
    bool isNumber(string str) {
        int n = str.size(), i = 0;
        
        bool number = false;
        bool space = false;
        bool sci = false;
        bool afterE = true;
        
        while(str[i] == ' ') {i++;}
        if(str[i] == '-' || str[i] == '+') {
            i++;
        }
        
        int start = i, ecnt = 0, dcnt = 0;
        for(; i < n; i++) {
            if(str[i] == 'e') {
                if(ecnt > 0 || i == start || i == n-1 || number == false) {
                    return false;
                }
                sci = true;
                afterE = false;
                number = false;
                ecnt++;
                continue;
            }
            if(str[i] == '.') {
                if(dcnt || sci || (i > start && str[i-1] == ' ')) {return false;}
                dcnt++;
                continue;
            }
            if(isdigit(str[i])) {
                if(space) {return false;}
                number = true;
                afterE = true;
                continue;
            } else {
                if(str[i] == ' ') {
                    if(ecnt && afterE) {return false;}
                    space = true;
                    continue;
                } else if(str[i] == '+' || str[i] == '-') {
                    if(ecnt && (i > start && str[i-1] == 'e')) {
                        afterE = false;
                        continue;
                    }
                } else {
                    return false;
                }
            }
        }
        return number && afterE;
        //return number;
    }
};