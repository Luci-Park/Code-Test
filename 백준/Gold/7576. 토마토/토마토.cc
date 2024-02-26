#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int M, N;
    int dy [] = {0, 1, 0, -1};
    int dx [] = {1, 0, -1, 0};
    cin >> M >> N;
    vector<vector<int>> graph(N, vector<int>(M));
    queue<pair<int, int>> q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 1){
                q.push(make_pair(i, j));
            }
        }
    }
    while(!q.empty()){
        int y = q.front().first, x = q.front().second; q.pop();
        for(int i = 0; i<4; i++){
            int ty = y + dy[i], tx = x + dx[i];
            if(ty < 0 || tx < 0 || ty >= N || tx >= M|| graph[ty][tx] != 0) continue;;
            graph[ty][tx] = graph[y][x] + 1;
            q.push(make_pair(ty, tx));
        }        
    }
    int max = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(graph[i][j] == 0){
                cout << -1;
                return 0;
            }
            if(graph[i][j] > max){
                max = graph[i][j];
            }
        }
    }
    cout << max - 1;
}