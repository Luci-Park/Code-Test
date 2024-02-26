# include <iostream>
# include <vector>
# include <stack>
# include <string>
using namespace std;

int main ()
{
  int N;
  stack<int> s;
  string rslt;
  int nextPushNum = 1;
  int popNum = 0;
  cin >> N;
  for(int i = 1; i<= N; i++){
    int num;
    cin >> num;
    while(nextPushNum <= num){
      s.push(nextPushNum++);
      rslt += "+\n";
    }
    while(!s.empty() && s.top() >= num){
      popNum += 1;
      if(s.top() == num && popNum != i) {
        cout << "NO";
        return 0;
      }
      s.pop();
      rslt += "-\n";
      
    }
  }
  cout << rslt;
  return 0;
}