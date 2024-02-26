#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int getNum(int n, int idx){
    if(idx == 0) return n - 1;
    if(idx == 1) return n + 1;
    return n * 2;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    vector<int> dist(100002, INT_MAX);
    int n, k;
    int answer = 0;
    cin >> n >> k;
    dist[n] = 0;
    queue<pair<int,int>> q; q.push({0,n});
    while(!q.empty()){
        int t = q.front().first;
        int n = q.front().second;
        q.pop();
        if(t > dist[n]) continue;
        if(n == k && t == dist[n]){
            answer += 1;
            continue;
        }
        for(int i = 0; i < 3; ++i){
            int next = getNum(n, i);
            if(next < 0 || next > 100002) continue;
            if(dist[next] < t + 1) continue;
            if(next == k && t + 1 < dist[next]) answer = 0;
            dist[next] = t + 1;
            q.push({t + 1, next});
        }
    }
    cout << dist[k] <<"\n" << answer;
    
    

    return 0;
}
