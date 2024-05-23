#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int visited[20000] = {0, };
    bool graph[20000][20000] = {false, };
    for(int i =0; i < edge.size(); i++)
    {
        graph[edge[i][0] - 1][edge[i][1] - 1] = true;
        graph[edge[i][1] - 1][edge[i][0] - 1] = true;
    }
    int maxDist = 0;    
    int answer = 0;
    visited[0] = 1;
    queue<int> q; q.push(0);
    while(!q.empty())
    {
        int num = q.front(); q.pop();
        if(visited[num] > maxDist) {maxDist = visited[num]; answer = 0;}
        if(visited[num] == maxDist) answer += 1;
        for(int i = 0; i < n; i++)
        {
            if(!graph[num][i] || visited[i]) continue;
            visited[i] = visited[num] + 1;
            q.push(i);
        }
    }
    
    return answer;
}