#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct Tomato{
  int h, y, x, time;
};

bool IsValid(int n, int N){
  if(0 <= n && n < N) return true;
  return false;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[6][3] ={{1, 0, 0}, {-1,0,0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

    int N, M, H; cin >> M >> N >> H;
    queue<Tomato> q;
    vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M)));
    for(int k = H - 1; k >= 0; --k){
      for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
          cin >> box[k][i][j];
          if(box[k][i][j] == 1){
            Tomato newTomato = {k, i, j, 0};
            q.push(newTomato);
          }
        }
      }
    }
    int days = 0;
    while(!q.empty()){
      Tomato tomato = q.front(); q.pop();
      for(int i =0; i < 6; i++){
        int h = tomato.h + arr[i][0] , n = tomato.y + arr[i][1], m = tomato.x + arr[i][2];
        if(IsValid(h, H) && IsValid(n, N) && IsValid(m, M) && box[h][n][m] == 0){
          Tomato newTomato = {h, n, m, tomato.time + 1};
          box[h][n][m] = 1;
          if(days < newTomato.time) days = newTomato.time;
          q.push(newTomato);
        }
      }
    }
    for(int k = 0; k < H; k++){
      for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
          if(box[k][i][j] == 0) {cout << -1; return 0;}
        }
      }
    }
    cout << days;

    return 0;
}
