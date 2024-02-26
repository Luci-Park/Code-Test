    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    #include <limits.h>
    using namespace std;

    int tree[10000];

    void Postorder(int start, int end) {
        if (start < 0 || end > 10000 || start >= end) return;
        int root = tree[start];
        if (start == end - 1) { 
            cout << root << "\n";
            return;
        }
        int partition = start + 1;
        for (int i = start + 1; i < end; ++i) {
            if (root < tree[i]) {
                partition = i;
                break;
            }
        }
        Postorder(start + 1, partition);
        Postorder(partition, end);
        cout << root << "\n";

    }


    int main()
    {
        ios_base :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int idx = 0;
        int num = -1;
        while (cin >> num) {
            tree[idx++] = num;
        }
        Postorder(0, idx);




        return 0;
    }
