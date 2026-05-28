class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = *(std::ranges::max_element(candies));
        vector<bool> answer(candies.size());
        for(int i =0; i < candies.size(); i++)
        {
            answer[i] = candies[i] + extraCandies >= maxCandy;            
        }

        return answer;
    }
};