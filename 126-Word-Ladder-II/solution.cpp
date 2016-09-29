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
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(end);
        vis[start] = 0;
        
        toVisit.push(start);
        while(!toVisit.empty()) {
            string word = toVisit.front();
            toVisit.pop();
            if(word == end) {break;}
            int step = vis[word];
            vector<string> wordNext;
            findNextWord(word, dict, step, wordNext);
        }
        path.push_back(start);
        dfsPath(start, end);
        return res;
    }
    
private:
    vector<vector<string>> res;
    unordered_map<string, int> vis;
    unordered_map<string, vector<string>> next;
    queue<string> toVisit;
    vector<string> path;
    
    void findNextWord(string word, unordered_set<string> &dict, int &step, vector<string> &wordNext) {
        for(int i = 0; i < word.size(); i++) {
            char origin = word[i];
            for(int j = 0; j < 26; j++) {
                word[i] = 'a' + j;
                if(origin == word[i] || dict.find(word) == dict.end()) {continue;}
                if(vis.find(word) == vis.end()) {
                    toVisit.push(word);
                    vis[word] = step + 1;
                }
                wordNext.push_back(word);
            }
            word[i] = origin;
        }
        next[word] = wordNext;
    }
    
    void dfsPath(string word, string end) {
        if(word == end) {
            //path.push_back(end);
            res.push_back(path);
        }
        vector<string> vec = next[word];
        int step = vis[word];
        for(int i = 0; i < vec.size(); i++) {
            if(vis[vec[i]] != step + 1) {continue;}
            path.push_back(vec[i]);
            dfsPath(vec[i], end);
            path.pop_back();
        }
    }
};