class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int arr[3]; int l = 0;
        for(int i = 0; i < nums.size() && l < 3; ++i)
        {
            if(l == 0 || nums[i] > arr[l - 1])
            {
                arr[l++] = nums[i];
            }
            else
            {
                if(nums[i] <= arr[0]) arr[0] = nums[i];
                else if(nums[i] <= arr[1]) arr[1] = nums[i];
            }
        }
        return l == 3;
    }
};