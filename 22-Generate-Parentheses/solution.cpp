/** Use two integers to count the remaining left parenthesis (n) and the right parenthesis (m) to be added. At each function call add a left parenthesis if n >0 and add a right parenthesis if m>0. Append the result and terminate recursive calls when both m and n are zero.
 **/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //vector<string> res;
        //string str;
        generateRecur("", n, 0);
        return res;
    }
private:
    vector<string> res;
    
    void generateRecur(string str, int n, int m){
        if(n == 0 && m == 0){
            res.push_back(str);
            return;
        }
        
        if(m > 0){generateRecur(str + ')', n, m - 1);}
        if(n > 0){generateRecur(str + '(', n - 1, m + 1);}
    }
};