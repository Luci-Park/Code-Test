    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    #include <limits.h>
    using namespace std;

    int main()
    {
        ios_base :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int dist[1000];
        vector<pair<int, int>> graph[1000];
        priority_queue<pair<int, int>>q;
        int N, M, start, end; cin >> N >> M;
        for (int i = 0; i < N; ++i)
            dist[i] = INT_MAX;
        while (M--) {
            int from, to, cost;
            cin >> from >> to >> cost;
            graph[from - 1].push_back({ to - 1, cost });
        }
        cin >> start >> end;
        dist[start - 1] = 0;
        q.push({ 0, start - 1 });
        while (!q.empty()) {
            int city = q.top().second, cost = q.top().first * -1;
            q.pop();
            if (dist[city] < cost) continue;
            for (auto c : graph[city]) {
                int adjCity = c.first, adjCost = c.second + cost;
                if (adjCost < dist[adjCity]) {
                    dist[adjCity] = adjCost;
                    q.push({ adjCost * -1, adjCity });
                }
               
            }
        }


        cout << dist[end - 1];

        return 0;
    }
