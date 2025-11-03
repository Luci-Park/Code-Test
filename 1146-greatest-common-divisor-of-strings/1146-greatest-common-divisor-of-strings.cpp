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
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) 
            return "";
        int len = gcd(max(str1.size(), str2.size()), min(str1.size(), str2.size()));
        return str1.substr(0, len);
    }
};