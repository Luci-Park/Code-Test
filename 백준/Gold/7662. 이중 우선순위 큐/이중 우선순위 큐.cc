#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        multiset<int> ms;
        int M; cin >> M;
        while (M--) {
            char cmd; int num; cin >> cmd >> num;
            if (cmd == 'I') {
                ms.insert(num);
            }
            else if (cmd == 'D' && ms.size() > 0) {
                if (num > 0) {
                    ms.erase(--ms.end());
                }
                else {
                    ms.erase(ms.begin());
                }
            }
        }
        if (ms.size() <= 0) cout << "EMPTY" << endl;
        else cout << *(--ms.end()) << " " << *ms.begin() << endl;
    }

    return 0;
}