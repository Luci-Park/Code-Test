    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    #include <climits>
    #define FULL 10000
    using namespace std;
    
    int stack[FULL];
    int idx = -1;

    void Push(int x) {
        stack[++idx] = x;
    }

    int Size() {
        return idx + 1;
    }

    int Pop() {
        if (Size()) {
            int x = stack[idx--];
            return x;
        }
        else {
            return -1;
        }
    }


    int Empty() {
        return idx <= -1;
    }

    int Top() {
        if(Size())
            return stack[idx];
        return -1;
    }
    



    int main()
    {
        ios_base :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int N; cin >> N;
        while (N--) {
            string cmm; 
            cin >> cmm;
            if (cmm == "push") {
                int param;
                cin >> param;
                Push(param);

            }else if(cmm == "pop") {
                cout << Pop()<< "\n";
            }
            else if (cmm == "size") {
                cout << Size() << "\n";
            }
            else if (cmm == "empty") {
                cout << Empty() << "\n";
            }
            else if(cmm == "top")
            {
                cout << Top() << "\n";
            }
        }   

        return 0;
    }
