# include <iostream>
# include <vector>
# include <climits>
using namespace std;

long long length(vector<long long> v, long long h){
  long long sum = 0;
  for(auto i:v){
    if(i > h) sum += i - h;
  }
  return sum;
}

int main ()
{ 
  long long N, M;
  long long min = 0, max = 0;
  vector<long long> v;
  long long rslt = 0;
  scanf("%lld %lld", &N, &M);
  while(N--){
    long long height; scanf("%lld", &height);
    v.push_back(height);
    if(max < height) max = height;    
  }
  while(min <= max){
    long long mid = (min + max)/2;
    long long l = length(v, mid);
    if(l >= M){
      if(mid > rslt) rslt = mid;
      min = mid + 1;
    }else{
      max = mid - 1;
    }
  }
  cout << rslt;
  return 0;
}