# include <iostream>
# include <string>
# include <stack>
using namespace std;

int main ()
{ int N;
  scanf("%d", &N);
  stack<int> s;
  stack<int> zeros;
  while(N--){
    int command;
    scanf("%d", &command);
    if(command ==0){
      s.pop();
    }else{
      s.push(command);
    }
  }
  long long sum = 0;
  while(!s.empty()){
    sum += (long long)s.top(); s.pop();
  }
  cout << sum;
  return 0;
}