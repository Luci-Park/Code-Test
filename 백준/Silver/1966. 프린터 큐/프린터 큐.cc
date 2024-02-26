# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

int main ()
{
  int T;
  scanf("%d", &T);
  while(T--){
    int N, M;
    queue<pair<int, int>> papers;
    priority_queue<int> priorities;
    scanf("%d %d", &N, &M);
    for(int i = 0; i< N; i++) {
      int num; scanf("%d", &num);
      priorities.push(num);
      papers.push(make_pair(i, num));
    }
    int cnt = 1;
    while(!papers.empty()){
      while(priorities.top() > papers.front().second){
        pair<int, int> p = papers.front(); papers.pop(); papers.push(p);
      }
      if(papers.front().first == M)break;
      priorities.pop(); papers.pop();
      cnt += 1;
    }
    printf("%d\n", cnt);
  }
  return 0;
}




