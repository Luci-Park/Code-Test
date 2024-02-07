# include <iostream>
# include <vector>
using namespace std;

int main ()
{ 
  int maxNum = 10000, N;
  vector<int> v(maxNum + 1, 0);
  scanf("%d", &N);
  while(N--){
    int num; scanf("%d", &num);
    v[num] += 1;
  }
  for(int i = 1; i<= maxNum; i++){
    while(v[i]--) printf("%d\n", i);
  }
  return 0;
}