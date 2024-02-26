# include <iostream>
# include <vector>
using namespace std;

int main ()
{ 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int M = 10007;
  int N;
  cin >>N;
  vector<int>v(N + 1);
  v[1] = 1; v[2] = 3;
  for(int i = 3; i<= N; i++){
    v[i] = (v[i - 1] + v[i-2] * 2) % M;
  }
  cout << v[N]<< "\n";
  return 0;
}