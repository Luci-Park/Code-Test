# include <iostream>
# include <vector>
using namespace std;

int main ()
{ 
  int T, N;
  cin >> T;
  vector<vector<int>> arr(41, vector<int>(2, -1));
  arr[0][0] = 1; arr[0][1] = 0;
  arr[1][0] = 0; arr[1][1] = 1;
  while(T--){
    cin >> N;
    for(int i = 2; i <= N; i++){
      if(arr[i][0] == -1){
        arr[i][0] = arr[i-1][0] + arr[i - 2][0];
        arr[i][1] = arr[i-1][1] + arr[i - 2][1]; 
      }
    }
    printf("%d %d\n", arr[N][0], arr[N][1]);
  }
  return 0;
}