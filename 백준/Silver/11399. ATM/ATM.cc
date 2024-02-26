#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> q;
    int N;
    scanf("%d", &N);
    int i = N;
    while(i--){
        int num;
        scanf("%d", &num);
        q.push(num * -1);
    }
    long long sum = 0;
    while(!q.empty()){
        sum += q.top() * -1 * N--; q.pop();
    }
    cout << sum;

    return 0;
}