class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        if(nums.size() == 1)  return 0;
        
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        int count = 0;
        while(l < r)
        {
            int rslt = nums[l] + nums[r];
            if(rslt == k)
            {
                count += 1;
                l += 1;
                r -= 1;
            }
            else if(rslt < k)
                l += 1;
            else r -= 1;
        }
        return count;
    }

};