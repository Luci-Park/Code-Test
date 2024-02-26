#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        vector<string> p(N);
        for(int i =0; i < N; ++i)
            cin >> p[i];
        if(N <= 32)
        {
            int min = 100001;
            for(int i =0; i < N; i++)
            {
                for(int j =0; j < N; ++j)
                {
                    for(int k = 0; k < N; ++k)
                    {
                        if(i == j || j == k || k == i) continue;
                        int sum = 0;
                        for(int a = 0; a < 4; a++)
                        {
                            if(p[i][a] != p[j][a]) sum++;
                            if(p[j][a] != p[k][a]) sum++;
                            if(p[k][a] != p[i][a]) sum++;
                        }
                        if(sum < min)
                            min = sum;
                    }
                }
            }
            cout << min <<"\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    return 0;
}
