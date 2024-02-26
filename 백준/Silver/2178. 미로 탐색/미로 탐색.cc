#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int N){
    if(i < 0 || i >= N) return false;
    return true;
}

int main()
{
    int N, M;
    vector<vector<int>> graph;
    
    int dy[] = {1, 0 , -1, 0};
    int dx[] = {0, 1, 0, -1};
    
    
    cin >> N >> M;
    graph.resize(N);
    for(int i = 0; i<N; i++){
        string temp;
        cin >> temp;
        for(char& c: temp){
            int num = (c - '0') * -1;
            graph[i].push_back(num);
        }
    }
    graph[0][0] = 1;
    pair<int, int> p = make_pair(0, 0);
    queue<pair<int, int>> q; q.push(p);
    while(!q.empty()){
        p = q.front(); q.pop();
        int y = p.first; int x = p.second; 
        for(int k = 0; k < 4; k++){
            int tx = x + dx[k]; int ty = y + dy[k];
            if(!isValid(tx, M) || !isValid(ty, N) || graph[ty][tx] != -1) continue;
            graph[ty][tx] = graph[y][x] + 1 ;
            q.push(make_pair(ty, tx));
        }
    }
    cout << graph[N-1][M-1];
    
    return 0;
}