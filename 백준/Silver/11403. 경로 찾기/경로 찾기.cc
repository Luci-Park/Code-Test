# include <iostream>
# include <vector>
# include <queue>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<vector<int>> graph(N, vector<int>(N));
  vector<vector<int>> result(N, vector<int>(N, 0));
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      cin >> graph[i][j];
    }
  }
  for(int i = 0; i < N; ++i) {
    queue<int> q;
    q.push(i);
    while(!q.empty()){
      int next = q.front(); q.pop();
      for(int j = 0; j < N; ++j){
        if(graph[next][j] && !result[i][j]){
          result[i][j] = 1;
          q.push(j);
        }
      }
    }
  }
  for(auto i : result){
    for(auto j : i){
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}