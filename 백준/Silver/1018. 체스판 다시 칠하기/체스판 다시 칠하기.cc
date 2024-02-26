/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int CheckWhite(vector<string> board, int startRow, int startCol){
    int num = 0;
    string Board[2] = {"WBWBWBWB", "BWBWBWBW"};
    for(int i = startRow; i < startRow + 8; i++){
        for(int j = startCol; j < startCol + 8; j++){
            if(board[i][j] != Board[(i - startRow)%2][j-startCol]){
                num += 1;
            }
        }
    }
    return num;
}
int CheckBlack(vector<string> board, int startRow, int startCol){
    int num = 0;
    string Board[2] = {"BWBWBWBW", "WBWBWBWB"};
    for(int i = startRow; i < startRow + 8; i++){
        for(int j = startCol; j < startCol + 8; j++){
            if(board[i][j] != Board[(i - startRow)%2][j-startCol]){
                num += 1;
            }
        }
    }
    return num;
}
int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> board;
    int answer = 100;
    for(int i = 0; i< N; i++){
        string input;
        cin >> input;
        board.push_back(input);
    }
    for(int i = 0; i <= N - 8; i++){
        for(int j = 0; j <= M - 8; j++){
            answer = min({answer, CheckWhite(board, i, j), CheckBlack(board, i, j)} );
        }
    }
    cout << answer;
    return 0;
}
