# include <iostream>
# include <vector>
# include <cmath>
using namespace std;

int main ()
{ 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >>N;
  vector<int> sqrs;
  vector<int> sum(N + 1, 0);
  int idx = 0;
  for(int i = 1; i*i <= N; i++){
    int num = i*i;
    sqrs.push_back(num);
    sum[num] = 1;
  }
  if(!sum[N]){
    for(int i = 2; i <= N; i++){
      if(sum[i] == 1) {
        ++idx;
        continue;
      }
      int min = 5;
      for(int j =idx; j >= 0; j--){
        if(sum[i-sqrs[j]] < min) {
          min = sum[i-sqrs[j]];
        }
      }
      sum[i] = min + 1;
    }
  }
  cout << sum[N];
  return 0;
}