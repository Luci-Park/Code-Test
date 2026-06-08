class Solution {
public:
    bool isVowel(char c)
    {
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
    int maxVowels(string s, int k) {
        int maxC = 0;
        int count = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(isVowel(s[i]))
                count += 1;
            if(i >= k && isVowel(s[i - k]))
                count -= 1;
            maxC = max(maxC, count);
        }
        return maxC;
    }
};