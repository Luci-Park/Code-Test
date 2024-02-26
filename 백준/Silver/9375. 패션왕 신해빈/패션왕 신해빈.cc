# include <iostream>
# include <unordered_map>
# include <string>
using namespace std;

int main ()
{ 
  int T;
  cin >>T;
  while(T--){
    int n; cin >> n;
    string c, type;
    unordered_map<string, int> m;
    while(n--){
      cin >> c >> type;
      if(m.find(type) != m.end()){
        ++m[type];
      }else{
        m.insert({type, 2});
      }
    }
    long long result = 1;
    for(auto& it: m){
      result *= it.second;
    }
    cout << result - 1<<"\n";
  }
  return 0;
}