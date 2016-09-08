class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for(char ch: s){
            if(ch == '('){
                left++;
            }else if(ch == ')'){
                if(left > 0){
                    left--;
                }else{
                    right++;
                }
            }
        }
        dfs(s, "", 0, left, right, 0);
        return res;
    }
private:
    vector<string> res; 
    void dfs(const string &s, string path, int start, int left, int right, int open){
        //base case
        if(start == s.size()){
            if(left == 0 && right == 0 && open == 0){
                res.push_back(path);
            }
            return;
        }
        if(left < 0 || right < 0 || open < 0){return;}
        
        char c = s[start];
        if(c == '('){
            if (start == 0 || s[start - 1] != c) {
                //remove the '('
                for (int i = 0; start + i < s.size() && s[start + i] == c && i + 1 <= left; ++i){
                    dfs(s, path, start + i + 1, left - i - 1, right, open);
                }
            }
            dfs(s, path + c, start + 1, left, right, open + 1);//keep ')'
        }else if(c == ')'){
            if (start == 0 || s[start - 1] != c) {
                //remove the ')'
                for (int i = 0; start + i < s.size() && s[start + i] == c && i + 1 <= right; ++i) {
                    dfs(s, path, start + i + 1, left, right - i - 1, open);
                }
            }
            dfs(s, path + c, start + 1, left, right, open - 1);
        }else{
            dfs(s, path + c, start + 1, left, right, open);
        }
    }
};