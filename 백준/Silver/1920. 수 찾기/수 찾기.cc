# include <iostream>
# include <vector>
# include <stack>
# include <string>
# include <algorithm>
using namespace std;

int main ()
{
  int N, M;
  vector<long long> arr;
  scanf("%d", &N);
  for(int i = 0; i< N; i++){
    long long num;
    scanf("%lld", &num);
    arr.push_back(num);
  }
  sort(arr.begin(), arr.end());

  scanf("%d", &M);
  
  for(int i = 0; i< M; i++){
    long long target;
    scanf("%lld", &target);
    int high = arr.size() - 1,low = 0;
    bool found = false;
    while(low <= high){
      int mid = (low + high)/2;
      if(arr[mid] == target) {
        found = true;
        break;
      }
      if(arr[mid] > target){
        high = mid -1;
      }else{
        low = mid + 1;
      }
    }
    printf("%d\n", found);
  }
  return 0;
}
