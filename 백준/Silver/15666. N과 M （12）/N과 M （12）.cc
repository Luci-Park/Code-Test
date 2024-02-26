#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
vector<int>numbers;

void add(vector<int> num, int depth) {
    if (depth == m) {
        for (int i = 0; i < m; ++i)
            cout << num[i] << " ";
        cout << endl;
        return;
    }
    int prev = 0;
    int prevNum = depth == 0 ? 0 : num[depth - 1];
    for (int i = 0; i < n; ++i) {
        if (numbers[i] == prev || numbers[i] < prevNum) continue;
        num[depth] = numbers[i];
        prev = numbers[i];
        add(num, depth + 1);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    numbers = vector<int>(n);
    vector<int> num(m);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    add(num, 0);
    return 0;
}
