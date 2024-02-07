# include <iostream>
# include <string>
# include <cmath>
using namespace std;

bool isPali(string str){
  for(int i = 0; i< str.size()/2; i++){
    if(str[i] != str[str.size() - i - 1])return false;
  }
  return true;
}

int main ()
{
  while(1){
    int num;
    cin >> num;
    if(num ==0) break;
    string number = to_string(num);
    if(isPali(number))cout << "yes\n";
    else cout << "no\n";
  }
}


