//how about 0, 1?
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()){return res;}
        res.push_back("");  // add a seed for the initial case
        vector<string> letterMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        for(int i = 0; i < digits.size(); i++){
            int num = digits[i] - '0';
            if(num == 0 || num == 1){continue;}
            string chars = letterMap[num];
            
            vector<string> path;
            for(int j = 0; j < chars.size(); j++){
                for(int k = 0; k < res.size(); k++){
                    path.push_back(res[k] + chars[j]);
                }
            }
            swap(path, res);
        }
        return res;
    }
};