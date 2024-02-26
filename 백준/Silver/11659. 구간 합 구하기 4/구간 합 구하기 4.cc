# include <iostream>
# include <vector>
using namespace std;

int main ()
{ 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M;
  cin >>N >> M;
  vector<int>v(N + 1);
  v[0] = 0;
  cin >> v[1];
  for(int i = 2; i<=N; i++){
    cin >> v[i];
    v[i] += v[i-1];
  }
  while(M--){
    int i , j; cin >> i >> j;
    cout << v[j]-v[i-1]<<"\n";
  }
  return 0;
}