#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; cin >> N;
    vector<vector<int>> triangle (N);
    for (int i = 0; i < N; ++i) {
        for(int j = 0; j <= i; ++j){
            int a; cin >> a;
            triangle[i].push_back(a);
        }
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            if (j == 0){
                triangle[i][j] += triangle[i - 1][0];
            }
            else if (j == triangle[i].size() - 1) {
                triangle[i][j] += triangle[i - 1][j - 1];
            }
            else {
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
    }
    cout << *max_element(triangle[N - 1].begin(), triangle[N - 1].end());

    return 0;
}
