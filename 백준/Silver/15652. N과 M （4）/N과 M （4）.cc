#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[9] = {0,};
bool visited[9] = {false,};

void dfs(int lev, int num)
{
    if(lev == m)
    {
        for(int i = 0; i < m; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for(int i = num; i <= n; i++)
    {
        arr[lev] = i;
        dfs(lev + 1, i);
    }
}

int main() {
    cin >> n >> m;
    dfs(0, 1);
}