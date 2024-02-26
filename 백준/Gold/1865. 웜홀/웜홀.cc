#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void Ans(int N, int M, int W){
    int INF = INT_MAX/3;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));
    while(M--){
        int S,E,T; cin >> S >> E >> T;
        graph[S][E] = min(graph[S][E], T);
        graph[E][S] = min(graph[E][S], T);
    }
    while(W--){
        int S,E,T; cin >> S >> E >> T;
        graph[S][E] = min(graph[S][E], -T);
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            for(int k = 1; k <= N; ++k){
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    
    for(int i = 1; i <= N; ++i){
        if(graph[i][i] < 0) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--)
    {
        int N, M, W; cin >> N >> M >> W;
        Ans(N, M, W);
        cout << "\n";
    }
    return 0;
}
