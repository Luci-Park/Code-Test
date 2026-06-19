class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans; ans.reserve(asteroids.size());
        for(int a : asteroids)
        {
            if(a > 0) ans.push_back(a);
            else
            {
                int absa = abs(a);
                bool alive = true;
                while(!ans.empty() && ans.back() > 0 && alive)
                {
                    if(ans.back() < absa) ans.pop_back();
                    else if (ans.back() == absa){ans.pop_back(); alive = false;}
                    else alive = false;
                }
                if(alive) ans.push_back(a);
            }
        }
        return ans;
    }
};