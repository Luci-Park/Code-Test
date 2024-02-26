# include <iostream>
# include <string>
# include <cmath>
using namespace std;

int main ()
{
  int n;
  cin >> n;
  int num = 666;
  int cnt = 1;
  while(cnt != n){
    num += 1;
    if(to_string(num).find("666") != string::npos) cnt += 1;
  }

  cout << num;
  return 0;
}