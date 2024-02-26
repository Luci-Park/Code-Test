# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main ()
{ 
  long long N;
  cin >>N;
  vector<int> v(N + 1);
  v[1]=0;
  for(int i = 2; i <= N; i++){
    int a= N, b = N, c = N;
    a = v[i - 1];
    if(i%3 == 0) b = v[i/3];
    if(i%2 == 0) c = v[i/2];
    v[i] = std::min({a, b, c}) + 1;
  }
  cout << v[N];
  
  return 0;
}