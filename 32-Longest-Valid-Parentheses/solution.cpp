class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int maxLen = 0;
        stack<int> store;//use int for later use index distance compute the maxLen
        
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                store.push(i);
            }else{  //==')'
                if(!store.empty()){
                    if(s[store.top()] == '('){ //a new valid pair  
                        store.pop();
                    }else{                  //invalid pair
                        store.push(i);
                    }
                }else{
                    store.push(i);
                }
            }
        }
        //after the for loop,all valid paren are not in stack
         //use difference of index, to find the maxLen
        if(store.empty()){
            maxLen = n;
        }else{
            int larger = n;//the first diff is between '\n'(the index n) and the store.top()
            int smaller = 0;
            while(!store.empty()){
                smaller = store.top();
                store.pop();
                //-1 for the valid paren is between two index
                maxLen = max(maxLen, larger - smaller - 1);
                larger = smaller;
            }
            maxLen = max(maxLen, larger);
        }
        return maxLen;
    }
};