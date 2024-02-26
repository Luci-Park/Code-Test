#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, W;
    cin >> n >> W;
    vector<int> weight(n);
    vector<int> value(n);
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) dp[i][w] = 0;
            else if (weight[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w],
                    dp[i - 1][w - weight[i - 1]]
                    + value[i - 1]);
            }
            else dp[i][w] = dp[i - 1][w];
        }
    }
    cout << dp[n][W];
    return 0;
}
