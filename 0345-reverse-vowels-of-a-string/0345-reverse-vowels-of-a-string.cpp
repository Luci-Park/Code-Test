class Solution {
public:
    bool isVowel(char c)
    {
        c = tolower(c);
        switch(c)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            return true;
            default:
            return false;
        }
    }
    string reverseVowels(string s) {
        stack<char> cs;
        queue<int> q;
        for(int i = 0; i < s.length(); i++)
        {
            if(isVowel(s[i]))
            {
                cs.push(s[i]);
                q.push(i);
            }
        }
        while(!cs.empty())
        {
            s[q.front()] = cs.top();
            cs.pop();
            q.pop();
        }
        return s;
    }
};