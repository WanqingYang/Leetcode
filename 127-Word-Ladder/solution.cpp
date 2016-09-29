/**The idea is simpy to begin from start, then visit its neighbors, then the non-visited neighbors of its neighbors... Well, this is just the typical BFS structure.

To simplify the problem, we insert end into dict. Once we meet end during the BFS, we know we have found the answer. We maintain a variable dist for the current distance of the transformation and update it by dist++ after we finish a round of BFS search (note that it should fit the definition of the distance in the problem statement). Also, to avoid visiting a word for more than once, we erase it from dict once it is visited.
 **/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        wordDict.insert(endWord);
        queue<string> toVisit;
        addNextWords(beginWord, wordDict, toVisit);
        int dist = 2;
        while (!toVisit.empty()) {
            int num = toVisit.size();
            for (int i = 0; i < num; i++) {
                string word = toVisit.front();
                toVisit.pop();
                if (word == endWord) return dist;
                addNextWords(word, wordDict, toVisit);
            }
            dist++;
        }
        return 0;
    }
private:
    void addNextWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
        wordDict.erase(word);
        for (int p = 0; p < (int)word.length(); p++) {
            char letter = word[p];
            for (int k = 0; k < 26; k++) { 
                word[p] = 'a' + k;
                if (wordDict.find(word) != wordDict.end()) {
                    toVisit.push(word);
                    wordDict.erase(word);
                }
            }
            word[p] = letter;
        } 
    } 
};

/*class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        //if(beginWord == endWord)??
        wordDict.insert(endWord); //dont forget!!!
        int ladder = 2;
        queue<string> toVisit;
        findNextWord(beginWord, wordDict, toVisit);
        
       /* while(!toVisit.empty()) {
            string word = toVisit.front();
            toVisit.pop();
            ladder++;
            if(word == endWord) {return ladder;}
            //if(wordDict.find(word) != wordDict.end()) {
            wordDict.erase(word);
            findNextWord(word, wordDict, toVisit);
            //}
        }*/
        
       /* while(!toVisit.empty()) {
            int _size = toVisit.size();
            for(int i = 0; i < _size; i++) {
                string word = toVisit.front();
                toVisit.pop();
                if(word == endWord) {return ladder;}
                //wordDict.erase(word);
                findNextWord(word, wordDict, toVisit);
            }
            ladder++;
        }
        return 0;
    }
    
private:    
    void findNextWord(string word, unordered_set<string>& wordDict, queue<string> &toVisit) {
        wordDict.erase(word);
        for(int i = 0; i < word.size(); i++) {
            char origin = word[i];
            for(int j = 0; i < 26; j++) {
                word[i] = 'a' + j;
                if(wordDict.find(word) != wordDict.end()) {
                    toVisit.push(word);
                    wordDict.erase(word);
                }
            }
            word[i] = origin;
        }
    }
};