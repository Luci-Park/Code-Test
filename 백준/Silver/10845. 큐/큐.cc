    #include <iostream>
    #include <climits>
    #define FULL 10000
    using namespace std;
    
    int queue[FULL];
    int qsize = 0;
    int front = 0;
    int back = 0;

    void Push(int x) {
        queue[back++] = x;
        qsize++;
    }

    int Size() {
        return qsize;
    }

    int Pop() {
        if (Size()) {
            int x = queue[front++];
            qsize--;
            return x;
        }
        else {
            return -1;
        }
    }


    int Empty() {
        return qsize == 0;
    }

    int Front() {
        if (Size())
            return queue[front];
        return -1;
    }
    int Back() {
        if(Size())
            return queue[back - 1];
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
            else if(cmm == "front")
            {
                cout << Front() << "\n";
            }
            else if (cmm == "back")
            {
                cout << Back() << "\n";
            }
        }   

        return 0;
    }
