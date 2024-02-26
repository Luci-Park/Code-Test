#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int coins[n];
    int numOfCoins = 0;
    int coinIdx = n-1;
    for(int i =0; i<n; ++i){
        cin >>coins[i];
    }
    while(k > 0){
        numOfCoins += k/coins[coinIdx];
        k %= coins[coinIdx--];
    }
    
    cout<<numOfCoins;

    return 0;
}