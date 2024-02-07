#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;    
    --n;
    
    int layer = 1;
    while(n > 0){
        n -= layer * 6;
        ++layer;
    }
    cout <<layer;
    
    return 0;
}