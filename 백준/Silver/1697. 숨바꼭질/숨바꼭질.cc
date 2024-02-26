#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    int min = 0, max = 100000;
    cin >> N >> K;
    if(N == K){
        cout << 0;
        return 0;
    }
    std::queue<int> q;
    std::vector<int> distance(max + 1, -1);
    int op [] = {-1, 1, 2};
    q.push(N);
    distance[N] = 0;
    while(!q.empty()){
        int n = q.front(); q.pop();
        for(int i =0; i < 3; i++){
            int c;
            if(i < 2) c = n + op[i];
            else c = n * op[i];
            if(c < min || c > max|| distance[c] != -1)continue;
            q.push(c);
            distance[c] = distance[n] + 1 ;
            if(c == K){
                cout << distance[c];
                return 0;
            }
        }
    }
    return 0;
}
