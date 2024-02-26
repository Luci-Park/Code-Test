#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    const int INF = INT_MAX / 3;
    int N, M, X;
    cin >> N >> M >> X;
    auto map = vector<vector<int>>(N + 1, vector<int>(N + 1, INF));
    auto rslt = vector<int>(N + 1, INF);
    int answer = 0;
    while(M--)
    {
        int s, e, l;
        cin >> s >> e >> l;
        map[s][e] = l;
    }
    
    {
        rslt[X] = 0;
        priority_queue<pair<int, int>>pq; pq.push({0, X});
        while(!pq.empty())
        {
            int d = -pq.top().first, v = pq.top().second; pq.pop();
            if(d > rslt[v]) continue;
            for(int i = 1; i <= N; ++i)
            {
                if(d + map[v][i] < rslt[i])
                {
                    rslt[i] = d + map[v][i];
                    pq.push({-rslt[i], i});
                }
            }
        }
    }
    
    for(int i =1; i <= N; i++)
    {
        if(i == X) continue;
        auto dist = vector<int>(N + 1, INF);
        dist[i] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push({0, i});
        while(!pq.empty())
        {
            int d = -pq.top().first, v = pq.top().second; pq.pop();
            if(v == X) break;
            if(d > dist[v]) continue;
            for(int j =0; j <= N; j++)
            {
                if(d + map[v][j] < dist[j])
                {
                    dist[j] = d + map[v][j];
                    pq.push({-dist[j], j});
                }
            }
        }
        rslt[i] += dist[X];
        if(rslt[i] > answer)
            answer = rslt[i];
    }
    cout << answer;
    
    
    
    return 0;
}
