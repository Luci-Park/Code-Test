#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M; string str;
    cin >> N >> M; cin.ignore();
    getline(cin, str);
    int tot = 0; int sub =0;
    for(int i = 0; i < M-2; ++i){
      if(str.substr(i, 3) == "IOI"){
        sub += 1;
        ++i;
        if(sub == N){
          sub -= 1; tot += 1;
        }
      }
      else{
          sub = 0;
      }
    }
    cout << tot;
    return 0;
}
