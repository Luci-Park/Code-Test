#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    vector<int> warp(101, 0);
    vector<int> visited(101, -1);
    std::queue<int> q;
    cin >> N >> M;
    for(int i = 0; i < N + M; i++){
        int from, to;
        cin >> from >> to;
        warp[from] = to;
    }
    visited[1] = 0;
    q.push(1);
    while(!q.empty()){
        int n = q.front(); q.pop();
        for(int i = 1; i <= 6; i++){
            int num = n + i;
            if(num > 100) continue;
            while(warp[num] != 0){num = warp[num];}
            if(visited[num] == -1){ 
                visited[num] = visited[n] + 1; 
                if(num == 100){
                    break;
                }
                q.push(num);
            }
        }
    }
    cout << visited[100];
    return 0;
}