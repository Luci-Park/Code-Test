class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        ans.reserve(s.size());
        for(char c : s)
        {
            if(c != '*') ans += c;
            else ans.pop_back();
        }
        return ans;
    }
};