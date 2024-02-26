# include <iostream>
# include <vector>
# include <climits>
# include <numeric>
# define MAX 1000000
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> graph(N + 1, vector<int>(N + 1, MAX));
  while(M--){
    int to, from;
    cin >> to >> from;
    graph[to][from] = 1; graph[from][to] = 1;
  }
  
  for(int k = 1; k <= N; ++k){
    for(int i = 1; i <= N; ++i)
      for(int j = 1; j <= N; ++j){
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
      }
  }
  int min = MAX;
  int answer = -1;
  for(int i = 1; i <= N; ++i){
    int sum = 0;
    for(int j = 1; j <= N; ++j){
      sum += graph[i][j];
    }
    if(sum < min){
      min = sum; answer = i; 
    }
  }
  cout << answer;
  return 0;
}