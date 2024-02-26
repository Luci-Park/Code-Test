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
        int n, m; cin >> n >> m;
        int INF = INT_MAX / 2;
        vector<vector<int>>dp(n, vector<int>(n, INF));
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            if(w < dp[u - 1][v - 1]) dp[u - 1][v - 1] = w;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i == j) continue;
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == INF) dp[i][j] = 0;
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        return 0;
    }
