
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> student;
bool compare(pair<int, int>a, pair<int, int>b){
    return(a.first > b.first && a.second > b.second);
}

int main()
{
    int N;
    cin >> N;
    pair<int,int> info[N];
    int number[N];
    
    for(int i =0; i < N; ++i){
        int w, h;
        cin >> w >> h;
        info[i] = make_pair(w, h);
    }
    
    for(int i =0; i<N; ++i){
        int sum = 1;
        for(int j =0; j< N; ++j){
            if(i == j) continue;
            if(compare(info[j], info[i])){
                ++sum;
            }
        }
        cout << sum<<" ";
    }
    
    
    return 0;
}