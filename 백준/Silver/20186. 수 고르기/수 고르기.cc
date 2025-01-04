#include <iostream>
#include <algorithm>
using namespace std;
int num[5000];
int n, k;
int main()
{
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i =0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);
    int sum = 0;
    for(int i =0; i < k; i++)
    {
        sum -= i;
        sum += num[n - 1 - i];
    }
    cout << sum;
    
    
    return 0;
}