class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si = 0;
        
        for(int i = 0; i < t.size() && si < s.size(); ++i)
        {
            if(s[si] == t[i])
                si += 1;
        }
        
        return si == s.size();
    }
};