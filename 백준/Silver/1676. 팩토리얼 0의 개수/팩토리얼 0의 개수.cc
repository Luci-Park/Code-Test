#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; cin >> N;
    
    int num10 = 0;
    int num2 = 0;
    int num5 = 0;
    for(int i = 2; i <= N; i++){
        int n = i;
        while(n%2 ==0){
            n /= 2; ++num2;
        }
        while(n%5 == 0){
            n /= 5; ++num5;
        }
        int minnum = min(num2, num5);
        num10 += minnum;
        num2 -= minnum;
        num5 -= minnum;
    }
    cout << num10;
    
    return 0;
}
