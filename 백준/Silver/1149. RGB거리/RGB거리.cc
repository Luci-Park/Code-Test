#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N, r, g, b;
    int dp[3] = {0};
    cin >> N;
    for(int i =0 ; i<N; ++i){
        cin>> r >> g >> b;
        int nxtR = min(dp[1], dp[2]) + r;
        int nxtG = min(dp[0], dp[2]) + b;
        int nxtB = min(dp[0], dp[1]) + g;
        dp[0] = nxtR;
        dp[1] = nxtG;
        dp[2] = nxtB;
    }
    
    int ans = min(dp[0], dp[1]);
    ans = min(ans, dp[2]);
    cout << ans;
    
    return 0;
}