class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;
        if(flowerbed.size() == 1) return !flowerbed[0];
        if(n == flowerbed.size()) return false;

        int i =0; 
        while(i < flowerbed.size() && n)
        {
            if(flowerbed[i])
            {
                i += 2;
            }
            else
            {
                if((i == 0 || !flowerbed[i - 1]) && (i == flowerbed.size() - 1 || !flowerbed[i + 1]))
                {
                    n -= 1;
                    flowerbed[i] = 1;
                    i += 2;
                }
                else
                {
                    i += 1;
                }
            }
        }
        return n <= 0;
    }
};