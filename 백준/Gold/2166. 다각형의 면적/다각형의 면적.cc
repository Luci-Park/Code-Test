#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<long long>X;
    vector<long long>Y;
    long long x1,y1;
    for(int i=0; i<N; i++)
    {
        long long x,y;
        cin >> x >> y;
        if(i == 0)
        {
            x1 = x;
            y1 = y;
        }
        X.push_back(x);
        Y.push_back(y);
        
    }
    X.push_back(x1);
    Y.push_back(y1);
    long double sum = 0;
    for(int i=0; i<N; i++)
    {
        sum += X[i]*Y[i+1];
        sum -= Y[i]*X[i+1];
    }
    sum = abs(sum);
    sum /= 2;
    cout<<fixed<<setprecision(1)<<sum;
}