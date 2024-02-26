# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
  if(a.second != b.second) return a.second > b.second;
  return a.first < b.first;
}

int main ()
{
  int N, avg = 0, mid = 0, freq = 0, range;
  vector<int> v;
  scanf("%d", &N);
  for(int i = 0; i< N; i++){
    int num; scanf("%d", &num);
    v.push_back(num);
    avg += num;
  }
  sort(v.begin(), v.end());
  avg =  round((float)avg /N);
  range = v[v.size()-1] - v[0];
  mid = v[N/2];
  vector<pair<int, int>> count;
  for(int i = 0; i< N; i++){
    if(count.empty()||count[count.size() -1].first != v[i]){
      count.push_back(make_pair(v[i], 1));
    }else{
      count[count.size() -1].second += 1;
    }
  }
  
  sort(count.begin(), count.end(), comp);
  freq = count.size() > 1 && count[0].second == count[1].second ? count[1].first: count[0].first;
  printf("%d\n%d\n%d\n%d\n", avg, mid, freq, range);  

  return 0;
}



