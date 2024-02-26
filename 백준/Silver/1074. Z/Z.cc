#include <iostream>
#include <cmath>
using namespace std;

int r, c;

long long cnt(int y, int x, long long N){
    long long arr[4][2] = {{y, x}, {y, x + N/2}, {y + N/2, x}, {y + N/2, x + N/2}};
    long long sum = 0;
    if(N==2){
        for(int i = 0; i < 4; i++){
            if(arr[i][0] != r || arr[i][1] != c) sum += 1;
            else break;
        }
    }else{
        for(int i = 0; i < 4; i++){
            if(arr[i][0] <= r && r < arr[i][0] + N/2
                && arr[i][1] <= c && c < arr[i][1] + N/2){
                sum += cnt(arr[i][0], arr[i][1], N/2);
                break;
            }
            else{sum += N * N/4;}
        }
    }
    return sum;
}

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin >> N >> r >> c;
    cout << cnt(0, 0, pow(2, N));
    return 0;
}
