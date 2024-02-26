# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main ()
{ 
  int N;
  cin >>N;
  vector<vector<int>> v(N + 1, vector<int>(2, 0));
  for(int i = 1; i <= N; i++){
    cin >> v[i][0];
    v[i][1] = v[i][0];
  }
  for(int i = 2; i <= N; i++){
    v[i][0] += v[i-1][1];
    v[i][1] += max(v[i-2][0], v[i-2][1]);
  }
  cout << max(v[N][0],v[N][1]);
  
  return 0;
}