#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
bool visited[8];
int numbers[8];
int answer[8];

void add(int depth) {
    if (depth == m) {
        for(int i = 0; i < m; i++)
            cout << answer[i] << " ";
        cout << endl;
        return;
    }
    int prev = -1;
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        if(prev == numbers[i]) continue;
        answer[depth] = numbers[i];
        visited[i] = true;
        add(depth + 1);
        visited[i] = false;
        
        prev = numbers[i];
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    sort(numbers, numbers + n);
    add(0);

    return 0;
}