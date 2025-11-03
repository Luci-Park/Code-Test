class Solution {
private:
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
    bool isvalid(string& base, string& pattern)
    {
        if(base.size() == pattern.size()) return true;
        int i = pattern.size();
        while(i < base.size())
        {
            int idx = i % pattern.size();
            if(base[i++] != pattern[idx]) return false;
        }
        return true;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        string rslt = "";
        int len = gcd(max(str1.size(), str2.size()), min(str1.size(), str2.size()));
        for(int i = 0; i < len; i++)
        {
            if(str1[i] == str2[i])
                rslt += str1[i];
            else
                return "";
        }
        if(isvalid(str1, rslt) && isvalid(str2, rslt)) 
            return rslt;
        return "";
    }
};