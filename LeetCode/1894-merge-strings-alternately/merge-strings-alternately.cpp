class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string str = "";
        int i = 0;
        while(i < word1.size() && i < word2.size())
        {
            str += word1[i];
            str += word2[i];
            i+=1;
        }
        while(i < word1.size())
            str += word1[i++];
        while(i < word2.size())
            str += word2[i++];

        return str;
    }
};