#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
vector<int> numbers;
void dfs(string rslt, int before, int depth) {
    if (depth == M) { cout << rslt << "\n";  return; }
    for (int i = 0; i < N; ++i) {
        if (i < before) continue;
        dfs(rslt + to_string(numbers[i]) + " ", i, depth + 1);
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
    }
    sort(numbers.begin(), numbers.end());
    dfs("", 0, 0);

    return 0;
}
