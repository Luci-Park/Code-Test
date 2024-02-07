# include <iostream>
# include <vector>
# include <string>
# include <cmath>
using namespace std;

int main ()
{ 
  long long M = 1234567891, R = 31, r =1, result = 0; int L; 
  string str;
  scanf("%d", &L);
  cin >> str;
  for(char c: str){
    result = (result + (c-'a' + 1) * r)%M;
    r = (r*R)%M;
  }
  cout << result;
  return 0;
}