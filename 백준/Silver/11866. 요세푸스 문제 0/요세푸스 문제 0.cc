# include <iostream>
# include <queue>
# include <string>
using namespace std;

int main ()
{
  int N, K;
  queue<int> q;
  string answer = "<";
  scanf("%d %d", &N, &K);
  for(int i = 1; i<= N; i++){
    q.push(i);
  }
  while(!q.empty()){
    int i = K - 1;
    while(i--){
      q.push(q.front()); q.pop();
    }
    answer += to_string(q.front()) + ", "; q.pop();
  }
  answer = answer.substr(0, answer.size() - 2) + ">";
  cout << answer;

  return 0;
}
