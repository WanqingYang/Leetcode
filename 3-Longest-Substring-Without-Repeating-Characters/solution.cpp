class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = -1;
        int maxLen = 0;
        vector<int> charIndex(256, -1);    //??????????
      
        for(int i = 0; i < s.size(); ++i)
        {
          start = max(start, charIndex[s[i]]);
          charIndex[s[i]] = i;
          maxLen = max(maxLen, i - start);
        }
        return maxLen;
        
        
        /*int start = -1;               //this only beats 17%
        int maxLen = 0;
        unordered_map <char, int> mymap;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(mymap.count(s[i]) != 0)
            {
                start = max(start, mymap[s[i]]);
            }
            mymap[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
       return maxLen; */
    }
};