#include <iostream>
#include <map>

#define MOD 1000000007LL
using namespace std;

map<long long, long long> f;
long long fib(long long n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    if (f.count(n) > 0) // if key exists
        return f[n];
    if (n % 2 == 0)
    {
        long long m = n / 2;
        long long n1 = fib(m - 1);
        long long n2 = fib(m);
        f[n] = ((2LL * n1 + n2) * n2) % MOD;
        return f[n];
    }
    long long m = (n + 1) / 2;
    long long n1 = fib(m);
    long long n2 = fib(m - 1);
    f[n] = (n1 * n1 + n2 * n2) % MOD;
    return f[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long N;
    cin >> N;
    cout << fib(N);


    return 0;
}
