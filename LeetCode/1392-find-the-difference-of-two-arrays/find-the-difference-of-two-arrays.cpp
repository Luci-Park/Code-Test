class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1, s2;

        for(int i =0; i < nums1.size(); i++)
            s1.insert(nums1[i]);
        
        for(int i = 0; i < nums2.size(); i++)
            s2.insert(nums2[i]);

        vector<vector<int>> ans(2);
        auto i1 = s1.begin(), i2 = s2.begin();
        while(i1 != s1.end() && i2 != s2.end())
        {
            if(*i1 < *i2)
            {
                ans[0].push_back(*i1);
                i1++;
            }
            else if(*i1 > *i2)
            {
                ans[1].push_back(*i2);
                i2++;
            }
            else
            {
                i1++; i2++;
            }
        }
        while(i1 != s1.end())
        {
            ans[0].push_back(*i1);
            i1++;
        }
        while(i2 != s2.end())
        {
            ans[1].push_back(*i2);
            i2++;
        }
        return ans;
    }
};