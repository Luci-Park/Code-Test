#include <bits/stdc++.h>
#define MAXW 100000001
using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<list<pair<int, int>>> graph(n);
    vector<int> intensities(n, MAXW);
    vector<int> type(n, 0);
    priority_queue<pair<int, int>> pq;
    for(int i=0; i < summits.size(); i++)
    {
        type[summits[i] -1] = 1;
    }
    for(int i =0; i < gates.size(); i++)
    {
        pq.push({0, -(gates[i] - 1)});
        intensities[gates[i] - 1] = 0;
    }
    for(int i =0; i < paths.size(); i++)
    {
        int a = paths[i][0] - 1;
        int b = paths[i][1] - 1;
        int w = paths[i][2];
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    while(!pq.empty())
    {
        int intense = -pq.top().first, node = -pq.top().second; pq.pop();
        if(intense > intensities[node]) continue;
        for(auto i : graph[node])
        {
            if(max(i.second, intensities[node]) < intensities[i.first]) 
            {
                intensities[i.first] = max(i.second, intensities[node]);               
                if(!type[i.first]) pq.push({-i.second, -i.first});
            }
        }
    }
    vector<int> answer(2);
    answer[1] = MAXW;
    for(int i =0; i < summits.size(); i++)
    {
        int s = summits[i] - 1;
        if(intensities[s] < answer[1]) {answer[1] = intensities[s]; answer[0] = s + 1;}
        if(intensities[s] == answer[1] && answer[0] > s + 1) {answer[1] = intensities[s]; answer[0] = s + 1;}
    }
    return answer;
}