class Solution {
public:
    string reverseWords(string s) {
        stack<pair<int,int>> st;
        int b = -1;
        for(int i =0; i < s.size(); ++i)
        {
            if(s[i] != ' ' && b == -1)
                b = i;
            if(s[i] == ' ' && b != -1)
            {
                st.push({b, i - b});
                b = -1;
            }
        }

        if(b != -1)
            st.push({b, s.size() - b});

        if(st.empty()) return "";
        string ans = "";
        while(!st.empty())
        {
            pair<int, int> p = st.top(); st.pop();
            ans += s.substr(p.first, p.second);
            if(!st.empty()) 
            ans += " ";
        }
        return ans;
    }
};