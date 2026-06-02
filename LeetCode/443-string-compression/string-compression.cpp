class Solution {
public:
    void compress(vector<char>& chars, char c, int count, int& idx)
    {
        chars[idx++] = c;
        if(count > 1)
        {
            int start = idx;
            while(count)
            {
                chars[idx++] = '0' + (count % 10);
                count /= 10;
            }
            reverse(chars.begin() + start, chars.begin() + idx);
        }
    }

    int compress(vector<char>& chars) {
        char c = chars[0];
        int count = 1;
        int idx = 0;
        for(int i = 1; i < chars.size(); ++i)
        {
            if(chars[i] == c)
                count += 1;
            else
            {
                compress(chars, c, count, idx);
                c = chars[i];
                count = 1;
            }
        }
        compress(chars, c, count, idx);

        chars.resize(idx);
        return chars.size();
    }
};