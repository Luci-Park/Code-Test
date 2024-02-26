    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    #include <climits>
    using namespace std;
    
    int n;
    vector<vector<int>> graph;
    const int INF = INT_MAX / 3;

    int dijkstra(int from, int to) {
        vector<int>dist(n, INF);
        dist[from] = 0;
        priority_queue<pair<int, int>>pq; pq.push({ 0, from });
        while (!pq.empty()) {
            int d = -pq.top().first, v = pq.top().second; pq.pop();
            if (d > dist[v]) continue;
            if (v == to) break;
            for (int i = 0; i < n; ++i) {
                if (d + graph[v][i] < dist[i]) {
                    dist[i] = d + graph[v][i];
                    pq.push({ -dist[i], i });
                }
            }
        }
        return min(dist[to], INF);
    }


    int main()
    {
        ios_base :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int e, v1, v2;
        cin >> n >> e;
        graph = vector<vector<int>>(n, vector<int>(n, INF));
        while (e--) {
            int a, b, c;
            cin >> a >> b >> c;
            a -= 1; b -= 1;
            graph[a][b] = min(graph[a][b], c);
            graph[b][a] = min(graph[b][a], c);
        }
        cin >> v1 >> v2; v1 -= 1; v2 -= 1;
        int a2b = dijkstra(v1, v2); 
        if (a2b >= INF) {
            cout << -1;
            return 0;
        }
        int z2a2n = dijkstra(0, v1) + a2b + dijkstra(v2, n - 1);
        int z2b2n = dijkstra(0, v2) + a2b + dijkstra(v1, n - 1);
         
        int ans = min(z2a2n, z2b2n);
        ans = ans >= INF ? -1 : ans;
        cout << ans;
        return 0;
    }
