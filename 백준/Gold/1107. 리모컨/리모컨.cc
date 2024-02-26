#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<bool> broken(10, false);
int Creatable(int num){
  string numstr = to_string(num);
  for(char c: numstr){
    if(broken[c-'0']) {
      return 0;
    }
  }
  return numstr.size();
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int currPosition = 100;
    int N, M;
    cin >> N >> M;
    while(M--){
      int num; cin >> num;
      broken[num] = true;
    }
    int cnt_100 = abs(100 - N);
    int sum = cnt_100;
    for(int i = 0; i <= N + cnt_100; ++i){
      int size = Creatable(i);
      if(i == 100 ||size == 0)continue;
      sum = min(size + abs(i - N), sum);
    }
    cout << sum;
    return 0;
}
