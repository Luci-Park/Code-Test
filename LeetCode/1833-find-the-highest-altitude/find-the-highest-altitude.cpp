class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int h = 0, ans = 0;
        for(int i =0; i < gain.size(); i++)
        {
            h += gain[i];
            ans = max(h, ans);
        }
        return ans;
    }
};