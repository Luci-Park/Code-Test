#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int D(int n) {
    return (n * 2) % 10000;
}
int S(int n) {
    return n == 0 ? 9999 : n - 1;
}
int L(int n) {
    return (n % 1000) * 10 + n / 1000;
}
int R(int n) {
    return (n % 10) * 1000 + n / 10;
}

string Command(int A, int B) {
    vector<bool> visited(10000, false);
    queue<pair<int, string>> q; q.push(make_pair(A, "")); visited[A] = true;
    while (!q.empty()) {
        int n = q.front().first; string command = q.front().second; q.pop();
        if (n == B) return command;
        int rslt[4] = { D(n), S(n), L(n), R(n) };
        string commands[4] = { "D", "S","L", "R"};
        for (int i = 0; i < 4; ++i) {
            if (visited[rslt[i]]) continue;
            visited[rslt[i]] = true;
            q.push(make_pair(rslt[i], command + commands[i]));
        }
    }

}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        cout << Command(A, B) << endl;
    }
    
    return 0;
}
