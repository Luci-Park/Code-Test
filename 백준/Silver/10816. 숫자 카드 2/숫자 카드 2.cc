# include <iostream>
# include <map>
# include <vector>
using namespace std;

int main ()
{ int N;
  map<int, int> m;
  scanf("%d", &N);
  while(N--){
    int n; scanf("%d", &n);
    if(m.find(n) == m.end()) m.insert({n, 1});
    else m[n] += 1;
  }
  scanf("%d", &N);
  vector<int> v;
  while(N--){
    int n; scanf("%d", &n);
    if(m.find(n) != m.end()) v.push_back(m[n]);
    else v.push_back(0);
  }
  for(int i : v){
    cout << i << " ";
  }
  return 0;
}