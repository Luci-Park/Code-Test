#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int>visited;
int order = 1;

void BFS(int x){
    queue<int>nxtN;
    visited[x] = order++;
    nxtN.push(x);
    while(!nxtN.empty()){
        int n = nxtN.front();
        nxtN.pop();
        for(auto &idx: graph[n]){
            if(visited[idx] == 0){
                visited[idx] = order++;
                nxtN.push(idx);
            }
        }
    }
}

int main()
{
    int N, E;
    cin >> N >> E;
    graph.resize(N + 1);
    visited.resize(N + 1, 0);
    
    for(int i = 0; i < E; ++i){
        int srcN, destN;
        cin >> srcN >> destN;
        graph[srcN].push_back(destN);
        graph[destN].push_back(srcN);
    }
    
    BFS(1);
    
    int cnt = 0;
    for(int i = 2; i<= N; ++i){
        if(visited[i] != 0){
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}