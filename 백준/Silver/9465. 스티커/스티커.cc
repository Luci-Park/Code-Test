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
    
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<vector<int>>stickers(2, vector<int>(N, 0));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> stickers[i][j];
            }
        }
        if (N > 1) {
            stickers[0][1] += stickers[1][0];
            stickers[1][1] += stickers[0][0];
            for (int col = 2; col < N; ++col) {
                stickers[0][col] += max(stickers[1][col - 1], stickers[1][col - 2]);
                stickers[1][col] += max(stickers[0][col - 1], stickers[0][col - 2]);
            }
        }
        cout << max(stickers[0][N - 1], stickers[1][N - 1]) << endl;
    }
    return 0;
}
