/**The idea is simpy to begin from start, then visit its neighbors, then the non-visited neighbors of its neighbors... Well, this is just the typical BFS structure.

To simplify the problem, we insert end into dict. Once we meet end during the BFS, we know we have found the answer. We maintain a variable dist for the current distance of the transformation and update it by dist++ after we finish a round of BFS search (note that it should fit the definition of the distance in the problem statement). Also, to avoid visiting a word for more than once, we erase it from dict once it is visited.
 **/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        //if(beginWord == endWord)??
        int ladder = 2;
        queue<string> toVisit;
        findNextWord(beginWord, wordDict, toVisit);
        
        while(!toVisit.empty()) {
            string word = toVisit.front();
            toVisit.pop();
            ladder++;
            if(word == endWord) {return ladder;}
            if(wordDict.find(word) != wordDict.end()) {
                wordDict.erase(word);
                findNextWord(word, wordDict, toVisit);
            }
        }
        return 0;
    }
    
private:    
    void findNextWord(string word, unordered_set<string>& wordDict, queue<string> &toVisit) {
        for(int i = 0; i < beginWord.size(); i++) {
            char orgin = word[i];
            for(int j = 0; i < 26; j++) {
                word[i] = 'a' + j;
                if(wordDict.find(word) != wordDict.end()) {
                    toVisit.push(word);
                }
            }
            word[i] = origin;
        }
    }
};