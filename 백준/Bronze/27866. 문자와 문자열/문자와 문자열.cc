#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    int idx;
    cin >> str >> idx;
    cout << str[--idx];

    return 0;
}
