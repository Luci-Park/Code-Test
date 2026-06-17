class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < n; c++)
            {
                bool flag = true;
                for(int i = 0; i < n; i++)
                {
                    if(grid[r][i] != grid[i][c])
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag) count += 1;
            }
        }
        return count;
    }
};