class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> result;
        string ans;
        vector<int> dp(s.size(), 0); 
        unordered_map<int, vector<int>> mapWord;
        findWords(0, s, wordDict, ans, dp, mapWord, result);
        return result;
    }
    //generate all the answers from mapWord, and store them to result
    void writeAnswer(string &s, string &ans, vector<string> &result, unordered_map<int, vector<int>> &mapWord, int index){
        if(index == s.size()){
            result.push_back(ans);
            return;
        }
        vector<int>* t = &mapWord[index];
        for(int i = 0; i < t->size(); ++i)
        {
            ans.append(" " + s.substr(index, (*t)[i] - index));
            writeAnswer(s, ans, result, mapWord, (*t)[i]);
            ans.erase(ans.size() - ((*t)[i] - index + 1));
        }
    }
    
    void findWords(int index, string &s, unordered_set<string>& wordDict, string ans, vector<int> &dp,
    unordered_map<int, vector<int>> &mapWord, vector<string> &result){
        if(index == s.size()){
            result.push_back(ans);
            return;
        }
        
        //for(int i = 1; i < s.size() - index; i++){
        for(int i = 1 + index; i <= s.size(); i++){
            //string sub = s.substr(index, i);
            string sub = s.substr(index, i - index);
            if(wordDict.find(sub) != wordDict.end()){ 
                //apend next candidate word to ans
                if(!ans.empty()) ans.append(" ");
                ans.append(sub);
                int old_size = result.size();
                if(dp[i] == 0){
                    findWords(i, s, wordDict, ans, dp, mapWord, result);
                    //remove the finished word from ans
                    int back_size = ans.size() == i ? i : i + 1;
                    ans.erase(ans.size() - back_size); //when finished pop;
                    if(result.size() > old_size){
                        dp[i] = 1;
                        //mapWord[i].push_back(i + sub.size()); //i is the word beginning index
                        mapWord[index].push_back(i); //i is the word beginning index
                    }else{
                        dp[i] = -1;
                    }
                }else if(dp[i] == 1){
                    //print the answer
                    writeAnswer(s, ans, result, mapWord, index);
                    /*
                    //cut branches
                    int mapSize = mapWord[i].size();
                    //if(!ans.empty()) ans.append(" ");
                    //ans.append(s.substr(index, i - index));
                    for(int j = 0; j < mapSize; j++){//each element in mapWord[i]
                        //append(start index, length)
                        //ans.append(s.substr(i, mapWord[i][j] - i + 1)); 
                        ans.append(" " + s.substr(i, mapWord[i][j] - i + 1)); 
                        for(int k = mapWord[i][j] + 1; k <= s.size() - 1; k = mapWord[k][0] + 1){
                            ans.append(s.substr(k, mapWord[k][0] - k + 1));
                        }
                        result.push_back(ans);
                    }
                    */
                }else{  //dp == -1;`
                    continue;
                }
            }
        }
    }
};