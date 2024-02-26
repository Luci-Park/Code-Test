# include <iostream>
# include <map>
# include <string>
using namespace std;

int main ()
{ 
  int N, M;
  cin >> N >> M;
  map<string, string> m;
  while(N--){
    string cite, pass;
    cin >> cite >> pass;
    m.insert({cite, pass});
  }
  while(M--){
    string cite; cin >> cite;
    cout << m[cite]<<"\n";
  }
  return 0;
}