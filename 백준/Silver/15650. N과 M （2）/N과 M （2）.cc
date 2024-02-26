#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[9] = {0,};
bool visited[9] = {false,};

void dfs(int lev, int prevNum)
{
    if(lev == m)
    {
        for(int i = 0; i < m; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for(int i = prevNum; i <= n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            arr[lev] = i;
            dfs(lev+1, i + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(0, 1);
}