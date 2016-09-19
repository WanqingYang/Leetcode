/** traverse all the char in string s, calculate how many '(' or ')' is leftover(can not find pair)
 * the dfs function
 **/

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
            // when you have continuous ( or ), only search from the head one:
            if (start == 0 || s[start - 1] != c) {//skip the repeating case

                //deal with continuous '('
                //remove '(', remove 1, 2, 3... 1 + i '(', depending on the num of continuous '('
                for (int i = 0; start + i < s.size() && s[start + i] == c && i + 1 <= left; ++i){
                    dfs(s, path, start + i + 1, left - i - 1, right, open);
                }
            }
            //keep ')'
            dfs(s, path + c, start + 1, left, right, open + 1);
        }else if(c == ')'){
            if (start == 0 || s[start - 1] != c) { //skip the repeating case
                //remove the ')'
                for (int i = 0; start + i < s.size() && s[start + i] == c && i + 1 <= right; ++i) {
                    dfs(s, path, start + i + 1, left, right - i - 1, open);
                }
            }
            //keep ')'
            dfs(s, path + c, start + 1, left, right, open - 1);
        }else{
            dfs(s, path + c, start + 1, left, right, open);
        }
    }
};

/*
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int remove_left=0, remove_right=0, pair=0;
        //use the unordered_set to deal with the duplicate cases
        unordered_set<string> result;
        //calculate the remained # of left and right parentheses
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(')   remove_left++;
            else if(s[i]==')'){
                if(remove_left > 0) remove_left--;
                else    remove_right++;
            }
        }
        help(0, 0, remove_left, remove_right, s, "", result);
        //change the unordered_set to vector
        return vector<string>(result.begin(), result.end());
    }
    
    //pair : record the () pair count in the solution
    //index : record the cur-position int the string s
    //remove_left : the number of left parentheses needed to delete
    //remove_right : the number of right parentheses needed to delete
    //s : origninal input string    solution : the current produced string
    //result : stores all the satisfied solution string
    
    void help(int pair, int index, int remove_left, int remove_right, const string& s, string solution, unordered_set<string>& result){
        //end condition
        if(index==s.size()){
            //check whether the remained string solution is right
            if(pair==0 && remove_left==0 && remove_right==0)    result.insert(solution);
            return;
        }
        //left-half-parentheses
        if(s[index]=='('){
            //remove the left-half-parentheses
            if(remove_left > 0)     help(pair, index+1, remove_left-1, remove_right, s, solution, result);
            //keep  the  left-half-parentheses
            help(pair+1, index+1, remove_left, remove_right, s, solution+s[index], result);
        }
        //right-half-parentheses
        else if(s[index]==')'){
            //remove the right-half-parentheses
            if(remove_right > 0)     help(pair, index+1, remove_left, remove_right-1, s, solution, result);
            //keep  the  right-half-parentheses
            if(pair > 0) help(pair-1, index+1, remove_left, remove_right, s, solution+s[index], result);
        }
        //other-characters
        else{
            help(pair, index+1, remove_left, remove_right, s, solution+s[index], result);
        }
    }
};