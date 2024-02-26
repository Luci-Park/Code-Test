#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    pair<int, int> startPos;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i =0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if(v[i][j] == 2)
            {
                startPos = make_pair(i, j);
                v[i][j] = 0;
            }
            v[i][j] = -v[i][j];
        }
    }
    
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    
    queue<pair<int, int>> q;
    q.push(startPos);
    
    while(!q.empty())
    {
        auto pos = q.front(); q.pop();
        for(int i =0; i < 4; ++i)
        {
            int y = pos.first + dy[i];
            int x = pos.second + dx[i];
            if(y < 0 || n <= y || x < 0 || m <= x) continue;
            if(v[y][x] >= 0) continue;
            v[y][x] = v[pos.first][pos.second] + 1;
            q.push({y, x});
        }
    }
    
    for(int i = 0; i < n; ++i)
    {
        for(int j =0; j < m; ++j)
        {
            cout << v[i][j] <<" ";
        }
        cout <<"\n";
    }
    
    return 0;
}
