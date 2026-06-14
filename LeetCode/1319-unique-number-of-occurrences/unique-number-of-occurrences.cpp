class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, uint> m;
        for(int i = 0; i < arr.size(); ++i)
        {
            auto it = m.find(arr[i]);
            if(it == m.end())
                m.insert({arr[i], 1});
            else
                it->second += 1;
        }
        unordered_set<int> s;
        for(auto it = m.begin(); it != m.end(); it++)
        {
             auto sit = s.find(it->second);
             if(sit == s.end())
                s.insert(it->second);
            else
                return false;
        }
        return true;
    }
};