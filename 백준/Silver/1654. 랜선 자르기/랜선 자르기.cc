# include <iostream>
# include <vector>
using namespace std;

bool CheckNum(vector<long long> lines, int N, long long size){
  int cnt = 0;
  for(int i = 0; i< lines.size(); i++){
    cnt += lines[i] / size;
  }
  return cnt >= N;
}

int main ()
{
  int N, K;
  long long low = 1, high = 0, rslt = 0;
  cin >> K >> N;
  vector<long long> lines;
  for(int i = 0; i<K; i++){
    long long cm;
    cin >> cm;
    lines.push_back(cm); 
    if(high < cm) high = cm;   
  }
  while(low <= high){
    long long mid = (low + high)/2;
    if(CheckNum(lines, N, mid)){
      low = mid + 1;
      if(mid > rslt) rslt = mid;
    }else{
      high = mid - 1;
    }
  }
  cout << rslt;
  return 0;
}
