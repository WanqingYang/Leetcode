class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char& c : s) {
            switch (c) {
                case '(': 
                case '{': 
                case '[': paren.push(c); break;
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                default: ; // pass
            }
        }
        return paren.empty() ;
    }
};

/*//use stack to store parenthesis, when traverse string, if parenthesis is a pair, pop it
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()){return true;}
        if(s.size() == 1){return false;}
        
        stack<char> check;
        int start = isLeft(s[0]);
        if(start == -1){return false;}//first paren is right paren
        check.push(s[0]);
        for(int i = 1; i < s.size(); i++){
            int left = isLeft(s[i]);
            if(left != -1){//paren is left
                check.push(s[i]);
            }else{// paren is right
                if(check.empty()){return false;}
                int right = isRight(s[i]);
                int topLeft = isLeft(check.top());
                if(right == topLeft){check.pop();}
                else{return false;}
            }
        }
        return check.empty();
    }
    
private:
    string leftP = "{[(";
    string rightP = "}])";
    
    int isLeft(char &a){
        for(int j = 0; j < 3; j++){
            if(a == leftP[j]){return j;}
        }
        return -1;
    }
    
    int isRight(char &b){
        for(int k = 0; k < 3; k++){
            if(b == rightP[k]){return k;}
        }
        return -1;
    }
};