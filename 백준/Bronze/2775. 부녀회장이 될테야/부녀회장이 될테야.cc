#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int v[T];
    
    for(int a = 0; a<T; ++a){
        int k, n;
        cin >> k >> n;
        int apt[k + 1][n];
    
        for(int i =0; i <= k; ++i){
            for(int j = 1; j<= n; ++j){
                if(i == 0){
                    apt[i][j-1] = j;
                }
                else{
                    if(j == 1){
                        apt[i][j - 1] = 1;
                    }
                    else{
                        apt[i][j-1] = apt[i-1][j-1] + apt[i][j-2];
                    }
                }
            }
        }
        v[a] = apt[k][n-1];
    }
    
    for(int a = 0; a < T; ++a){
        cout << v[a] << "\n";
    }
    
    return 0;
}