#include <bits/stdc++.h>
using namespace std;


int A, B, C;
long long int f(long long int y){
	if(y==1) return A%C;
	
	long long int k = f(y/2)%C;
	
	if(y%2==0) return k*k%C;
	else return k*k%C*A%C;
}
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> A >> B >> C;
    cout << f(B);
    
    return 0;
}
