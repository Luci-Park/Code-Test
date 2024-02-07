#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i<n; ++i){
        int j = i;
        int sum = i;
        while(j > 0){
            sum += j%10;
            j /= 10;
        }
        if(sum == n){
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}