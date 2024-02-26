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
        int A, B; cin >> A >> B;
        int maxLength = 100005;
        vector<int> dist(maxLength, maxLength);
        priority_queue<pair<int, int>> pq;
        dist[A] = 0;
        pq.push({ 0, -A });
        while (!pq.empty()) {
            int n = -pq.top().second;
            int d = -pq.top().first;
            pq.pop();
            if (d > dist[n]) continue;
            if (n == B) break;
            if (n * 2 < maxLength && d < dist[n * 2]) {
                pq.push({ -d, -n * 2 });
                dist[n * 2] = d;
            }
            if (n + 1 < maxLength && d + 1 < dist[n + 1]) {
                pq.push({ -d - 1, -n - 1 });
                dist[n + 1] = d + 1; 
            }
            if (n - 1 < maxLength && d + 1< dist[n - 1]) {
                pq.push({ -d - 1, - n + 1 });
                dist[n - 1] = d + 1;
            }
        }
        cout << dist[B];


        return 0;
    }
