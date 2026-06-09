class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, z = 0, ans = 0;
        for(int r = 0; r < nums.size(); r++)
        {
            if(!nums[r]) z += 1;
            while(z > k)
            {
                if(!nums[l]) z -= 1;
                l++;
            }
            ans = max(ans, r - l + 1);
        }   
        return ans;
    }
};