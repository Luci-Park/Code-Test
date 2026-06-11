class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int z = 0, l = 0, ans = 0, lastZ = 0;
        for(int r = 0; r < nums.size(); r++)
        {
            if(!nums[r])
            {
                if(z == 0)
                    z = 1;
                else
                    l = lastZ + 1;
                lastZ = r;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};