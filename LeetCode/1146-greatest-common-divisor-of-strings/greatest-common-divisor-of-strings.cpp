class Solution {
public:
    int gcd(int a, int b)
    {
        while(b)
        {
            int r = a % b;
            a = b;
            b = r;        
        }
        return a;
    }

    bool patternMatch(string& str, string& pattern)
    {
        for(int i = pattern.size(); i < str.size(); i++)
        {
            int j = i % pattern.size();
            if(pattern[j] != str[i]) return false;
        }
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        int len = gcd(max(str1.size(), str2.size()), min(str1.size(), str2.size()));
        string pattern = "";
        for(int i =0; i < len; i++)
        {
            if(str1[i] != str2[i]) return "";
            pattern += str1[i];
        }
        if(patternMatch(str1, pattern) && patternMatch(str2, pattern)) 
            return pattern;
        return "";
    }
};