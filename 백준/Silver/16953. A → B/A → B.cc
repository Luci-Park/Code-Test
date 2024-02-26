#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int A, B;
    cin >> A >> B;
    int answer = 1;
    
    while(B != A){
        if(B < A){
            answer = -1;
            break;
        }
        else if(B%10 == 1)B/=10;
        else if(B%2 == 0) B/=2;
        else{
            answer = -1;
            break;
        }
        ++answer;
    }
    
    cout << answer;
    return 0;
}
