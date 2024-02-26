    #include <iostream>
    #include <climits>
    #define FULL 10000
    using namespace std;
    
    int deque[FULL];
    int dsize = 0;
    int front = 0;
    int back = 0;

    int Foward(int idx) {
        return (FULL + idx - 1) % FULL;
    }
    int Backward(int idx) {
        return (FULL + idx + 1) % FULL;
    }

    int Size() {
        return dsize;
    }

    int Empty() {
        return dsize == 0;
    }

    void PushFront(int x) {
        if (!Empty())
            front = Foward(front);
        deque[front] = x;
        dsize++;
    }
    void PushBack(int x) {
        if (!Empty())
            back = Backward(back);
        deque[back] = x;
        dsize++;
    }

    int PopFront() {
        if (!Empty()) {
            int x = deque[front];
            front = Backward(front);
            dsize--;
            if (Empty()) back = front;
            return x;
        }
        return -1;
    }
    int PopBack() {
        if (!Empty()) {
            int x = deque[back];
            back = Foward(back);
            dsize--;
            if (Empty()) front = back;
            return x;
        }
        return -1;
    }

    int Front() {
        if (Size())
            return deque[front];
        return -1;
    }
    int Back() {
        if(Size())
            return deque[back];
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
            if (cmm == "push_front") {
                int param;
                cin >> param;
                PushFront(param);
            }else if (cmm == "push_back") {
                int param;
                cin >> param;
                PushBack(param);
            }
            else if(cmm == "pop_front") {
                cout << PopFront()<< "\n";
            }
            else if (cmm == "pop_back") {
                cout << PopBack() << "\n";
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
