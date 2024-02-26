    #include <iostream>
    #include <vector>
    #include <queue>
    
    using namespace std;
    vector<vector<int>> graph;
    int N;

    vector<bool> visited;

    void DFS(int root) {
        cout << root << " ";
        for (int i = 1; i <= N; ++i) {
            if (graph[root][i] && !visited[i]) {
                visited[i] = true;
                DFS(i);
            }
        }
    }
    void BFS(int root) {
        queue<int> q; q.push(root);
        visited[root] = true;
        while (!q.empty()) {
            int n = q.front(); q.pop();
            cout << n << " ";
            for (int i = 1; i <= N; ++i) {
                if (graph[n][i] && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

    }

    int main()
    {
        ios_base :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int M, r; cin >> N >> M >> r;
        graph = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
        visited = vector<bool>(N + 1, false);
        while (M--) {
            int u, v;
            cin >> u >> v;
            graph[u][v] = 1;
            graph[v][u] = 1;
        }
        visited[r] = true;
        DFS(r);
        cout << "\n";
        visited = vector<bool>(N + 1, false); visited[r] = true;
        BFS(r);

        return 0;
    }
