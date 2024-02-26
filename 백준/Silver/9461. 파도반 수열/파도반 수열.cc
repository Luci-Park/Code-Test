#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int j =0; j<t; ++j){
        int n;
        cin >> n;
        long fib[n];
        fib[0] = 1;
        fib[1] = 1;
        fib[2] = 1;
        for(int i = 3; i< n; ++i){
            fib[i] = fib[i-2] + fib[i-3];
        }
        printf("%ld\n", fib[n-1]);
    }    
    return 0;
}