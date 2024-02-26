#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> tree(n);
    vector<bool> visited(n, false);
    vector<int>answer(n);
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }
    visited[0] = true;
    queue<int> q; q.push(0);
    while(!q.empty()){
        int num = q.front(); q.pop();
        for(int i : tree[num]){
            if(visited[i]) continue;
            answer[i] = num + 1;
            visited[i] = true;
            q.push(i);
        }
    }
    for(int i = 1; i < n; ++i){
        printf("%d\n", answer[i]);
    }

    return 0;
}
