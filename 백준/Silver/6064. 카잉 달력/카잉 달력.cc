#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int m, n, x, y;
        scanf("%d %d %d %d", &m, &n, &x, &y);
        int limit = lcm(m, n);
        int year, ty;
        for(year = x; year <= limit; year += m){
            ty = year % n; 
            if(ty == 0) ty = n;
            if(ty == y) break;
            
        }
        if(year > limit || ty != y) year = -1;
        printf("%d\n", year);
    }
    
    return 0;
}
