    #include <iostream>
    #include <string>
    #define MAX 100000
    using namespace std;
    
    int heap[MAX];
    int heapSize = 0;
    
    bool childIsPrior(int p, int c){
        if(!(p + c))
            return c < p;
        return abs(c) < abs(p);
    }


    void HeapifyDown(int x, int idx) {
        int l = idx * 2 + 1;
        int r = idx * 2 + 2;
        int loc = idx;
        int val = x;
        if (l < heapSize && childIsPrior(val, heap[l])) {
            loc = l;
            val = heap[l];
        }if (r < heapSize && childIsPrior(val, heap[r])) {
            loc = r;
            val = heap[r];
        }
        if (loc != idx) {
            heap[loc] = x;
            heap[idx] = val;
            HeapifyDown(x, loc);
        }
    }

    void HeapifyUp(int x, int idx) {
        if(idx == 0) return;
        int p = (idx- 1) / 2;
        if (childIsPrior(heap[p], x)) {
            heap[idx] = heap[p];
            heap[p] = x;
            HeapifyUp(x, p);
        }
    }

    void Add(int x) {
        heap[heapSize] = x;
        HeapifyUp(x, heapSize++);
    }

    int Remove() {
        if (!heapSize) return 0;
        int x = heap[0];
        heap[0] = heap[--heapSize];
        HeapifyDown(heap[0], 0);
        return x;
    }
    void Print(){
        cout << "heapSize:" << heapSize << " -> ";
        for(int i = 0; i < heapSize; ++i){
            cout << heap[i]<< " ";
        }
        cout << endl;
    }
    int main()
    {
        ios_base :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int M; cin >> M;
        while (M--) {
            int cmd; cin >> cmd;
            if (cmd == 0)
                cout << Remove() << "\n";
            else
                Add(cmd);
            //Print();
        }

        return 0;
    }