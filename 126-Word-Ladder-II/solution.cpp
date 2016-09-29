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
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(end);
        //unordered_map<string, int> vis;
        //unordered_map<string, vector<string>> next;
        //queue<string> toVisit;
        //vector<string> path;
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
                if(origin == word[i] || wordDict.find(word) == end()) {continue;}
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

/*class Solution {
public:
    vector<vector<string> > ans; //private
    
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(end);
        int dsize = dict.size(), len = start.length();
        unordered_map<string, vector<string> > next; //string, 
        unordered_map<string, int> vis; //string, step to here
        queue<string> q;
        vector<string> path;
        ans.clear(); //
        q.push(start);
        vis[start] = 0;
        while (!q.empty()) {
            string s = q.front(); q.pop();
            if (s == end) break;
            int step = vis[s];
            vector<string> snext;
            for (int i = 0; i < len; i++) {
                string news = s;
                for (char c = 'a'; c <= 'z'; c++) {
                    news[i] = c;
                    if (c == s[i] || dict.find(news) == dict.end()) continue;
                    auto it = vis.find(news);
                    if (it == vis.end()) {
                        q.push(news);
                        vis[news] = step + 1;
                    }
                    snext.push_back(news);
                }
            }
            next[s] = snext;
        }
        path.push_back(start);
        dfspath(path, next, vis, start, end);
        return ans;
    }
    void dfspath(vector<string> &path,  unordered_map<string, vector<string> > &next,
                 unordered_map<string, int> &vis, string now, string end){
        if (now == end) ans.push_back(path);
        else {
            vector<string> vec = next[now];
            int visn = vis[now];
            for (int i = 0; i < vec.size(); i++) {
                if (vis[vec[i]] != visn + 1) continue;
                path.push_back(vec[i]);
                dfspath(path, next, vis, vec[i], end);
                path.pop_back();
            }
        }
    }
};