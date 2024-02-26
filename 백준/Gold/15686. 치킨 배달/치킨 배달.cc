    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    #include <climits>
    using namespace std;
    

    int N, M, H, C;
    vector<vector<pair<int, int>>> dist;
    bool picked[13] = { false };
    int minDist = INT_MAX;

    void CheckDist() {
        int sum = 0;
        for (int i = 0; i < H; ++i) {
            for (auto j : dist[i]) {
                if (!picked[j.second]) continue;
                sum += j.first;
                break;
            }
        }
        if (sum < minDist) minDist = sum;
    }

    void PickChicken(int idx, int depth) {
        if (depth == M) {
            CheckDist();
        }
        for (int i = idx; i < C; ++i) {
            picked[i] = true;
            PickChicken(i + 1, depth + 1);
            picked[i] = false;
        }
    }


    int main()
    {
        ios_base :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        cin >> N >> M;
        vector<pair<int, int>> houses, chickens;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int block; cin >> block;
                if (block == 1) houses.push_back({ i, j });
                else if (block == 2) chickens.push_back({ i, j });
            }
        }

        H = houses.size(); C = chickens.size();
        dist = vector<vector<pair<int, int>>>(H);
        for (int i = 0; i < H; ++i) {
            int hy = houses[i].first, hx = houses[i].second;
            for (int j = 0; j < C; ++j) {
                int cy = chickens[j].first, cx = chickens[j].second;
                dist[i].push_back({ abs(cy - hy) + abs(cx - hx), j }) ;
            }
            sort(dist[i].begin(), dist[i].end());
        }

        PickChicken(0, 0);
        cout << minDist;

        return 0;
    }
