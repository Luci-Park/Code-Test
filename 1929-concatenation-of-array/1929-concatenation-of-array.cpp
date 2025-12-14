class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int numsize = nums.size();
        vector<int>ans = vector<int>(numsize * 2);
        for(int i = 0; i < numsize; i++)
        {
            ans[i] = nums[i];
            ans[i + numsize] = nums[i];
        }
        return ans;
    }
};