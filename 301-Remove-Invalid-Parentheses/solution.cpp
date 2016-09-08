/*class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        
    }
};*/

class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    int left = 0, right = 0;
    for (char ch : s) {
      if (ch == '(') {
        ++left;
      } else if (ch == ')') {
        if (left > 0) {
          --left;
        } else {
          ++right;
        }
      }
    }
    res.clear();
    dfs(s, 0, left, right, 0, "");
    return res;
  }
  
private:
  void dfs(const string& s, int start, int left, int right, 
           int open, string path) {
    if (start == s.length()) {
      if (left == 0 && right == 0 && open == 0) {
        res.push_back(path);
      }
      return;
    }
    if (left < 0 || right < 0 || open < 0) return;
    
    char c = s[start];
    if (c == '(') {
      if (start == 0 || s[start - 1] != c) {
        for (int i = 0; start + i < s.length() && s[start + i] == c && i + 1 <= left; ++i) {
          dfs(s, start + i + 1, left - i - 1, right, open, path);
        }
      }
      
      dfs(s, start + 1, left, right, open + 1, path + c);
    } else if (c == ')') {
      if (start == 0 || s[start - 1] != c) {
        for (int i = 0; start + i < s.length() && s[start + i] == c && i + 1 <= right; ++i) {
          dfs(s, start + i + 1, left, right - i - 1, open, path);
        }
      }      
      
      dfs(s, start + 1, left, right, open - 1, path + c);
    } else {
      dfs(s, start + 1, left, right, open, path + c);
    }
  }

  vector<string> res;
};

/*class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int remove_left=0, remove_right=0, pair=0;
        /*** use the unordered_set to deal with the duplicate cases ***/
        unordered_set<string> result;
        /***  calculate the remained # of left and right parentheses  ***/
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(')   remove_left++;
            else if(s[i]==')'){
                if(remove_left > 0) remove_left--;
                else    remove_right++;
            }
        }
        help(0, 0, remove_left, remove_right, s, "", result);
        /*** change the unordered_set to vector ***/
        return vector<string>(result.begin(), result.end());
    }
    
    /***
    pair : record the () pair count in the solution
    index : record the cur-position int the string s
    remove_left : the number of left parentheses needed to delete
    remove_right : the number of right parentheses needed to delete
    s : origninal input string    solution : the current produced string
    result : stores all the satisfied solution string
    ***/
    void help(int pair, int index, int remove_left, int remove_right, const string& s, string solution, unordered_set<string>& result){
        /***   end condition       ***/
        if(index==s.size()){
            /*** check whether the remained string solution is right  ***/
            if(pair==0 && remove_left==0 && remove_right==0)    result.insert(solution);
            return;
        }
        /***    left-half-parentheses     ***/
        if(s[index]=='('){
            /***    remove the left-half-parentheses     ***/
            if(remove_left > 0)     help(pair, index+1, remove_left-1, remove_right, s, solution, result);
            /***    keep  the  left-half-parentheses     ***/
            help(pair+1, index+1, remove_left, remove_right, s, solution+s[index], result);
        }
        /***    right-half-parentheses     ***/
        else if(s[index]==')'){
            /***    remove the right-half-parentheses     ***/
            if(remove_right > 0)     help(pair, index+1, remove_left, remove_right-1, s, solution, result);
            /***    keep  the  right-half-parentheses     ***/
            if(pair > 0) help(pair-1, index+1, remove_left, remove_right, s, solution+s[index], result);
        }
        /***    other-characters     ***/
        else{
            help(pair, index+1, remove_left, remove_right, s, solution+s[index], result);
        }
    }
};