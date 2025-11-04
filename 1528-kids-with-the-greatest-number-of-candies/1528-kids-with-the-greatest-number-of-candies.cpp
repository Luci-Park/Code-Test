class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> answer(candies.size());
        int maxCandies = 0;
        for(int i =0 ; i < candies.size(); i++)
            maxCandies = max(maxCandies, candies[i]);

        for(int i = 0; i < candies.size(); i++)
            answer[i] = candies[i] + extraCandies >= maxCandies;
        
        return answer;

    }
};