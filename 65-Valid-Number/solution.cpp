class Solution {
public:
    bool isNumber(string str) {
        int n = str.size(), i = 0;
        
        while(str[i] == ' ') {i++;}
        if(str[i] == '-' || str[i] == '+') {
            i++;
        }
        
        bool point = false;
        bool sci = false;
        bool number = false;
        bool space = false;
        bool numAfterE = true;
        
        int start = i;
        for(; i < n; i++) {
            //cout << "str[i] = " << str[i] << endl; 
            if(isdigit(str[i])) {
                if(space) {return false;}
                number = true;
                numAfterE = true;
            } else if(str[i] == '.') {
                //if(point || sci || (i > start && str[i-1] == ' ')) {return false;}
                //if(sci || point || (i > start && str[i-1] == ' ')) {return false;}
                if(sci || point || space) {return false;}
                point = true;
            } else if(str[i] == 'e') {
                //if(sci || point || i == start || i == n-1 || number == false) {
                if(sci || !number) {
                    return false;
                }
                sci = true;
                numAfterE = false;
            } else if(str[i] == '+' || str[i] == '-') {
                if(i > start && str[i-1] != 'e') {
                    return false;
                }             
            } else if (str[i] == ' ') {
                space = true;
            } else {
                return false;
            }
        }
        return number && numAfterE;
    }
};