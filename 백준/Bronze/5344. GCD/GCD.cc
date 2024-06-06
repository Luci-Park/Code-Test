#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a < b) swap(a, b);
    int r = a % b;
    if (r) return gcd(b, r);
    return b;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << "\n";
    }
    return 0;
}
