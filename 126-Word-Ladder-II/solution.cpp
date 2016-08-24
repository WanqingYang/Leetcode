/*class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        m_ladders = vector<vector<string>>();
        m_wordLen = start.size();
        for (unordered_set<string>::iterator i=dict.begin(); i!=dict.end();i++){
            m_ladderLens[*i]=INT_MAX;
        }
        m_ladderLens[start] = 1;

        _ladderLength(start, end, dict);
        shortestLen = m_ladderLens[end]==INT_MAX ? 0 : m_ladderLens[end];
        _findLadders(start, end, vector<string>(), dict);

        return m_ladders;
    }

private:
    void _findLadders(const string& start, const string& end, vector<string> currentLadders, unordered_set<string>& dict){
        currentLadders.push_back(start);
        if (start==end && currentLadders.size()==shortestLen){
            m_ladders.push_back(currentLadders);
            return;
        }
        for (int i=0; i<=m_wordLen-1; i++){
            for (int j=0; j<=26-1; j++){
                string s = start;
                s[i] = 'a'+j;

                if (s!=start && dict.find(s)!=dict.end() && m_ladderLens[s]>=m_ladderLens[start]+1){
                    m_ladderLens[s]=m_ladderLens[start]+1;
                    _findLadders(s, end, currentLadders, dict);
                }
            }
        }
    }

    void _ladderLength(string start, string end, unordered_set<string> &dict){
        for (int i=0; i<=m_wordLen-1; i++){
            for (int j=0; j<=26-1; j++){
                string s = start;
                s[i] = 'a'+j;
                if (s!=start && 
                    dict.find(s)!=dict.end() && 
                    m_ladderLens[s]>m_ladderLens[start]+1){
                    m_ladderLens[s] = m_ladderLens[start]+1;
                    if (s != end){
                        _ladderLength(s, end, dict);
                    }
                }
            }
        }
    }    
    int m_wordLen;
    unordered_map<string, int> m_ladderLens;
    int shortestLen;
    vector<vector<string>> m_ladders;    
}; */

/**The solution contains two steps:
 * 1 Use BFS to construct a graph. 
 * 2. Use DFS to construct the paths from end to start.Both solutions got AC within 1s.

 *The first step BFS is quite important. I summarized three tricks
 *1. Using a MAP to store the min ladder of each word, or use a SET to store the words visited in current ladder, when the 
 *   current ladder was completed, delete the visited words from unvisited. That's why I have two similar solutions.
 *2. Use Character iteration to find all possible paths. Do not compare one word to all the other words and check if they only differ by one character.
 *3. One word is allowed to be inserted into the queue only ONCE. See my comments.
 **/
 //https://discuss.leetcode.com/topic/2857/share-two-similar-java-solution-that-accpted-by-oj

class Solution {
private:
    vector<vector<string>> results;
    vector<string> tmp;
    unordered_map<string, vector<string>> myMap;
    
    void backTrace(string endWord, string beginWord, vector<string> &path){
        if(endWord == beginWord){
            path.push_back(beginWord);
            results.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(endWord);
        if(!myMap[endWord].empty()){
            for(string s:myMap[endWord]){backTrace(s, beginWord, path);}
        }
       path.pop_back(); 
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        if(wordList.size() == 0){return results;}
        int min = INT_MAX;
        queue<string> q;
        q.push(beginWord);// if(beginWord){q.push(beginWord);}
        unordered_map<string, int> ladder;//store the shortest path to this word
        
        for(auto it=wordList.begin(); it!=wordList.end(); ++it){
            ladder[*it] = INT_MAX;
        }
        ladder[start] = 0;
        wordList.insert(endWord);
        
        //BFS: Dijisktra search
        while(!q.empty()){
            string word = q.front();
            int step = ladder[word] + 1; //'step' indicates how many steps are needed to travel to one word.
            if(step > min){break;}
           
            for(int i = 0; i < beginWord.size(); i++){
                for(char j = a; j <= z; j++){
                    string newWord = beginWord.replace(i, 1, j);
                    if(ladder.find(newWord) != ladder.end()){
                        if(step > ladder[newWord]){
                            continue;
                        }else if(step < ladder[newWord]{
                            q.push(newWord);
                            ladder[newWord] = step;
                        }else;  // It is a KEY line. If one word already appeared in one ladder,
					            // Do not insert the same word inside the queue twice. Otherwise it gets TLE
                        if(myMap.find(newWord) != myMap.end()){//Build adjacent Graph
                            vector<string> tmp = myMap[newWord].push_back(word);
                            myMap[newWord] = tmp;
                        }else{
                            vector<string> list(word); 
                            myMap[newWord] = list;
                        }
                        if(newWord == endWord){min = step;}
                    }
                }
            } 
        }
        //backtracking
        vector<string> path;
        backTrace(endWord, beginWord, path);
        return results;
    }
};