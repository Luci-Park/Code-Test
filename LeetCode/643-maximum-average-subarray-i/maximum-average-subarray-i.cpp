class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double av = 0;
        double ans = 0;
        double dk = static_cast<double>(k);

        for(int i =0; i < k; i++)
            av += nums[i] / dk;
        ans = av;
        for(int i = k; i < nums.size(); i++)
        {
            av -= nums[i - k] / dk;
            av += nums[i] / dk;
            ans = max(ans, av);
        }

        return ans;
    }
};