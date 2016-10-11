/**the question is asking the longest common prefix amongst all strings
 * check each char in strs[0][idx], compare it to all str[i][idx]
 * if == continue, if!= return
 **/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) {return "";}
        string prefix = "";
        for(int idx = 0; idx < strs[0].size(); prefix += strs[0][idx], idx++) {
        //for(int idx = 0; strs.size() > 0; prefix += strs[0][idx], idx++) {
            for(int i = 0; i < n; i++) {
                if(idx >= strs[i].size() || strs[0][idx] != strs[i][idx]) {
                //if(idx >= strs[i].size() ||(i > 0 && strs[i][idx] != strs[i-1][idx])) {
                    return prefix;
                }
            }
        }
        return prefix;
    }
};