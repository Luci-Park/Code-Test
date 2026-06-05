class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxn = 0;
        while(l < r)
        {
            int calc = (r - l) * min(height[r], height[l]);
            maxn = max(maxn, calc);
            if(height[l] < height[r])
                l+= 1;
            else
                r -= 1;
        }
        return maxn;
    }
};