class Solution {
public:
    bool vowel(char c)
    {
        switch(tolower(c))
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
        auto b = s.begin();
        auto e = s.end() - 1;
        while(b < e)
        {
            while(!vowel(*b) && b < e) b++;
            while(!vowel(*e) && b < e) e--;
            
            char t = *b;
            *b = *e;
            *e = t;

            b++;
            e--;
        }    
        return s;
    }
};