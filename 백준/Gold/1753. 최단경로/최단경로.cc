    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    #include <climits>
    using namespace std;

    int main()
    {
        ios_base :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int V, E, K; cin >> V >> E >> K;
        vector<vector<pair<int, int>>> graph(V);
        vector<int>dist(V, INT_MAX);
        while (E--) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u - 1].push_back({ v - 1, w });
        }
        dist[K - 1] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push({ 0, K - 1 });
        while (!pq.empty()) {
            int v = pq.top().second;
            int d = -pq.top().first;
            pq.pop();
            if (d > dist[v]) continue;
            for (auto i : graph[v]) {
                int u = i.first, w = i.second;
                if (dist[v] + w < dist[u]) {
                    dist[u] = dist[v] + w;
                    pq.push({ -dist[u], u });
                }
            }
        }
        for (auto i : dist) {
            if (i == INT_MAX) cout << "INF\n";
            else cout << i << "\n";
        }
        return 0;
    }
