/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
bool IsValid(int num, int N){
    if(num < 0 || num >= N)return false;
    return true;
}

int main()
{
    int T, M, N, K;
    int dy[] = {0, 1, 0, -1};
    int dx[] = {1, 0, -1, 0};
    cin >> T;
    for(int a =0; a < T; a++){
        cin >> M >> N >> K;
        int cnt = 0;
        std::vector<vector<int>> v(N, vector<int>(M, 0));
        for(int i = 0; i< K; i++){
            int x, y;
            cin >> x >> y;
            v[y][x] = 1;
        }
        for(int j =0; j< N; j++){
            for(int i = 0; i < M; i ++){
                if(v[j][i] != 1) continue;
                cnt += 1;
                pair<int, int> p = make_pair(j, i);
                queue<pair<int, int>>q; q.push(p);
                v[j][i] = 0;
                while(!q.empty()){
                    p = q.front(); q.pop();
                    int y = p.first; int x = p.second;
                    for(int k = 0; k<4; k++){
                        int ty = y + dy[k]; int tx = x + dx[k];
                        if(!IsValid(ty, N)||!IsValid(tx, M)|| v[ty][tx] != 1)continue;
                        q.push(make_pair(ty, tx));
                        v[ty][tx] = 0;
                    }
                }
            }
        }
        cout << cnt<<"\n";
    }

    return 0;
}
