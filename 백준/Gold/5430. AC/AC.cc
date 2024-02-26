#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int>CreateVector(string input){
  vector<int> rslt;
  string num = "";
  for(char c: input){
    if(c == ',' || c == '[' || c == ']'){
      if(!num.empty()){rslt.push_back(stoi(num)); num = "";}
    }else{
      num += c;
    }
  }
  return rslt;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin >> T;cin.ignore();
    while(T--){
      int n; string command, vstr; bool errorFlag = false;
      int dir = 1;
      vector<int> v;
      getline(cin, command); cin >> n; cin.ignore(); getline(cin, vstr);
      v = CreateVector(vstr);
      int start = 0, end = v.size();
      for(char c: command){
        if(c == 'R'){
          int temp = start;
          start = end - dir;
          end = temp - dir;
          dir *= -1;
        }else{
          if(start == end){
            cout << "error\n"; errorFlag = true; break;
          }else{
            start += dir;
          }
        }
      }
      if(!errorFlag){
        string rslt = "[";
        for(int i = start; i != end; i += dir){
          rslt += to_string(v[i]) + ",";
        }
        if(rslt.back() == ',')rslt[rslt.size() -1] = ']';
        else rslt += "]";
        cout << rslt << "\n";
      }
    }
    return 0;
}
