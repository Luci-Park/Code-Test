class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0;
        while(i < flowerbed.size() && n)
        {
            if(flowerbed[i])
            {
                i += 1;
                continue;
            }
            if((i - 1 >= 0 && flowerbed[i - 1]) || (i + 1 < flowerbed.size() && flowerbed[i + 1]))
            {
                i += 1;
                continue;
            }
            cout << i;
            n -= 1;
            i += 2;
        }
        return n == 0;
    }
};