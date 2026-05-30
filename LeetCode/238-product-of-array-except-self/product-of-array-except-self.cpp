class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int x = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            ans[i] *= x;
            x *= nums[i];
        }
        x = nums.back();
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            ans[i] *= x;
            x *= nums[i];
        }

        return ans;
    }
};