
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        string rslt = "";
        while(i < word1.size() && i < word2.size())
        {
            rslt += word1[i];
            rslt += word2[i++];
        }
        while(i < word1.size())
            rslt += word1[i++];
        while(i < word2.size())
            rslt += word2[i++];
        return rslt;
    }
};