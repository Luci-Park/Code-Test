#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
vector<int> numbers;
vector<bool> visited;
void dfs(string rslt, int depth) {
    if (depth == M) { cout << rslt << "\n";  return; }
    for (int i = 0; i < N; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        dfs(rslt + to_string(numbers[i]) + " ", depth + 1);
        visited[i] = false;
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    
    for (int i = 0; i < N; ++i) {
        int num; cin >> num; 
        numbers.push_back(num);
        visited.push_back(false);
    }
    sort(numbers.begin(), numbers.end());
    dfs("", 0);

    return 0;
}
