# include <iostream>
# include <string>
# include <stack>
using namespace std;

int main ()
{ 
  int N;
  scanf("%d", &N);
  string str;
  getline(cin,str);
  while(N--){
    stack<char>s; 
    bool flag = true;
    getline(cin, str);
    for(char c: str){
      if(c == '('){
        s.push(c);
      }else if(c == ')'){
        if(!s.empty() && s.top() == '(') s.pop();
        else {
          flag = false;
          break;
        }
      }
    }
    if(s.empty() && flag) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}