#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    int n, m; cin >> n >> m;
    
    vector<vector<int>> map(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    pair<int, int> startPos;
    
    for(int i =0; i < n; ++i)
    {
        string input; cin >> input;
        for(int j = 0; j < m; ++j)
        {
            if(input[j] == 'O') map[i][j] = 1;
            if(input[j] == 'P') map[i][j] = 2;
            if(input[j] == 'X') map[i][j] = 0;
            if(input[j] == 'I')
            {
                visited[i][j] = true;
                startPos.first = i;
                startPos.second = j;
            }
        }
    }
    
    int sum = 0;
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
            if(visited[y][x]) continue;
            if(!map[y][x]) continue;
            
            if(map[y][x] == 2) sum++;
            visited[y][x] = true;
            q.push({y, x});
        }
    }
    if(sum) cout << sum;
    else cout <<"TT";
    
    return 0;
}
