#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

bool IsValid(int n, int N){
  if(0 <= n && n < N) return true;
  return false;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; cin >> N; cin.ignore();
    int cntNo = 0, cntYes = 0;
    vector<vector<char>> v;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int dir [4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for(int i = 0; i < N; ++i){
      string str;
      vector<char> vchar;
      getline(cin, str);
      for(auto c:str) vchar.push_back(c);
      v.push_back(vchar);
    }
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        if(visited[i][j]) continue;
        ++cntNo;
        stack<pair<int, int>> s; s.push(make_pair(i, j));
        visited[i][j] = true;
        char target = v[i][j];
        while(!s.empty()){
          int y = s.top().first, x = s.top().second; s.pop();
          for(int k = 0; k < 4; k++){
            int ty = y + dir[k][0], tx = x + dir[k][1];
            if(IsValid(ty, N) && IsValid(tx, N) && !visited[ty][tx] && v[ty][tx] == target){
              visited[ty][tx] = true;
              s.push(make_pair(ty, tx));
            }
          }
        }
      }
    }
    visited = vector<vector<bool>>(N, vector<bool>(N, false));
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        if(visited[i][j]) continue;
        ++cntYes;
        stack<pair<int, int>> s; s.push(make_pair(i, j));
        visited[i][j] = true;
        if(v[i][j]== 'G') v[i][j] = 'R';
        char target = v[i][j];
        while(!s.empty()){
          int y = s.top().first, x = s.top().second; s.pop();
          for(int k = 0; k < 4; k++){
            int ty = y + dir[k][0], tx = x + dir[k][1];
            if(IsValid(ty, N) && IsValid(tx, N) && !visited[ty][tx]){
              if(v[ty][tx]== 'G') v[ty][tx] = 'R';
              if(v[ty][tx] == target){
                visited[ty][tx] = true;
                s.push(make_pair(ty, tx));
              }
            }
          }
        }
      }
    }
    cout << cntNo << " " << cntYes;

    return 0;
}
