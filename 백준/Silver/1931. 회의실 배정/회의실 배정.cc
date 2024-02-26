#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Comp(pair<int, int> a, pair<int, int> b){
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, sum = 1;
    cin >> N;
    vector<pair<int, int>> schedule;
    while(N--){
        int begin, end;
        cin >> begin >> end;
        schedule.push_back({begin, end});
    }
    sort(schedule.begin(), schedule.end(), Comp);
    int t = schedule[0].second;
    for(int i = 1; i < schedule.size(); i++){
        if(t <= schedule[i].first){
            sum += 1;
            t = schedule[i].second;
        }
    }
    cout << sum;
    return 0;
}
