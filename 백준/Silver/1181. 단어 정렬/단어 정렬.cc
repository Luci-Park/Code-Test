# include <iostream>
# include <string>
# include <set>
# include <vector>
# include <algorithm>
using namespace std;

bool compare(string a, string b){
  if(a.size() != b.size()) return a.size() < b.size();
  return a < b;
}

int main ()
{
  int N;
  set <string> st;
  cin >> N;
  for(int i = 0; i< N; i++){
    string s;
    cin >> s;
    st.insert(s);
  }
  vector<string> v(st.begin(), st.end());
  sort(v.begin(), v.end(), compare);
  for(int i = 0; i< v.size(); i++){
    cout << v[i] <<"\n";
  }
}
