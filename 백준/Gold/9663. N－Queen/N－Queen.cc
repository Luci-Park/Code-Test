#include <bits/stdc++.h>
#define MAX 15
using namespace std;

int col[MAX];
int n;

bool isValid(int row){
    for(int i = 0; i< row; ++i){
        if(col[i] == col[row] || abs(col[row] - col[i]) == row - i)// 대각선이거나 같은 라인
            return false;
    }
    return true;
}

int nQueen(int row){
    if(row == n){
        return 1;
    }
    int result = 0;
    for(int i = 0; i < n; ++i){
        col[row] = i;
        if(isValid(row)){
            result += nQueen(row + 1);
        }
    }
    return result;
}


int main() {
    cin >> n;
    printf("%d", nQueen(0));
}