# include <iostream>
# include <string>
# include <stack>
using namespace std;

int main ()
{ 
  char pairs[2][2] = { {'[', ']'}, {'(', ')'} };
  while(1){
    string str;
    getline(cin, str);
    if(str == ".") break;
    stack<char> s;
    bool flag = true;
    for(char c: str){
      if(c == '(' || c == '['){
        s.push(c);
      }else if(c == ')'){
        if(!s.empty() && s.top() == '(') s.pop();
        else {
          flag = false;
          break;
        }
      }else if(c == ']'){
        if(!s.empty() && s.top() == '[') s.pop();
        else {
          flag = false;
          break;
        }
      }
    }
    if(s.empty() && flag) cout << "yes\n";
    else cout << "no\n";
  }
  return 0;
}