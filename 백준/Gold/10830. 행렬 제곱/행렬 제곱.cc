#include<iostream>
using namespace std;

int A[5][5];
int multTemp[5][5];
int ans[5][5];
int n;
int mod = 1000;

void MultiMat(int a[5][5], int b[5][5]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            multTemp[i][j] = 0;
            for(int k = 0; k < n; k++){
                multTemp[i][j] += a[i][k] * b[k][j];
            }
            multTemp[i][j] %= mod;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = multTemp[i][j];
        }
    }
}

void Power(long long p){
    if(p == 1) return;
    if(p % 2 == 1){
        Power(p - 1);
        MultiMat(ans, A);
    }else{
        Power(p/2);
        MultiMat(ans, ans);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    long long p;
	cin >> n >> p;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++){
			cin >> A[i][j];
			ans[i][j] = A[i][j] % mod;
		}
	}
    
    Power(p);
    
	for(int i = 0; i <n; ++i){
	    for(int j = 0; j < n; ++j){
	        cout << ans[i][j] << " ";
	    }
	    cout << endl;
	}

}