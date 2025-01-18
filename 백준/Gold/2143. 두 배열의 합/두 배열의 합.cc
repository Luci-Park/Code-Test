#include <iostream>
#include <unordered_map>
using namespace std;

int t;
int A[1000], B[1000];
int n, m;
unordered_map<long, long> mA, mB;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> t >> n;
    for(int i =0; i < n; i++)
        cin >> A[i];
    cin >> m;
    for(int i =0; i < m; i++)
        cin >> B[i];
        
    for(int i =0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += A[j];
            auto iter = mA.find(sum);
            if(iter != mA.end())
            {
                iter-> second += 1;
            }
            else
            {
                mA.insert({sum, 1});
            }
        }
    }
        
    for(int i =0; i < m; i++)
    {
        int sum = 0;
        for(int j = i; j < m; j++)
        {
            sum += B[j];
            auto iter = mB.find(sum);
            if(iter != mB.end())
            {
                iter-> second += 1;
            }
            else
            {
                mB.insert({sum, 1});
            }
        }
    }    
    
    long answer = 0;
    for(auto iter = mA.begin(); iter != mA.end(); iter++)
    {
        auto biter = mB.find(t - iter->first);
        if(biter == mB.end())continue;
        answer += iter->second * biter->second;
    }
    cout << answer;
    return 0;
}