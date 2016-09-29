/**The above code can still be speeded up if we also begin from end. Once we meet the same word from start and end, we know we are done. This link provides a nice two-end search solution. I rewrite the code below for better readability. Note that the use of two pointers phead and ptail save a lot of time. At each round of BFS, depending on the relative size of head and tail, we point phead to the smaller set to reduce the running time
 **/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_set<string> left, right, *pleft, *pright;
        left.insert(beginWord);
        right.insert(endWord);
        
        unordered_set<string> tmp;
        int ladder = 1;
        while(!left.empty() && !right.empty()) {
            if(left.size() < right.size()) {
                pleft = &left;
                pright = &right;
            } else {
                pleft = &right;
                pright = &left;
            }
            
            for(auto it = pleft->begin(); it != pleft->end(); it++) {
                string word = *it; //????
                wordDict.erase(word);
                
                //if(pright->find(word) != pright->end()) {return ladder;}
                if(findNextWord(word, wordDict, tmp, ladder, pright)) {
                    return ladder;
                }
            }
            ladder++;
            swap(*pleft, tmp);
        }
        return 0;
    }
    
private:    
    bool findNextWord(string word, unordered_set<string>& wordDict, unordered_set<string> &tmp, int &ladder,
    unordered_map<string> *pright) {
        wordDict.erase(word);
        
        for(int i = 0; i < word.size(); i++) {
            char origin = word[i];
            for(int j = 0; j < 26; j++) {
                word[i] = 'a' + j;
                if(pright->find(word) != pright->end()) {
                    ladder++;
                    return true;
                }
                if(wordDict.find(word) != wordDict.end()) {
                    wordDict.erase(word);
                    tmp.insert(word);
                }
            }
            word[i] = origin;
        }
    }
    return false;
};


/**The idea is simpy to begin from start, then visit its neighbors, then the non-visited neighbors of its neighbors... Well, this is just the typical BFS structure.

To simplify the problem, we insert end into dict. Once we meet end during the BFS, we know we have found the answer. We maintain a variable dist for the current distance of the transformation and update it by dist++ after we finish a round of BFS search (note that it should fit the definition of the distance in the problem statement). Also, to avoid visiting a word for more than once, we erase it from dict once it is visited.
 **/

/*class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        //if(beginWord == endWord)??
        wordDict.insert(endWord); //dont forget!!!
        queue<string> toVisit;
        findNextWord(beginWord, wordDict, toVisit);
        
        int ladder = 2;
        /*while(!toVisit.empty()) {
            string word = toVisit.front();
            toVisit.pop();
            ladder++;
            if(word == endWord) {return ladder;}
            //if(wordDict.find(word) != wordDict.end()) {
            wordDict.erase(word);
            findNextWord(word, wordDict, toVisit);
            //}
        }*/ //this is wrong, for the same breath, ladder will be coninuously ++;
        
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
            for(int j = 0; j < 26; j++) {
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