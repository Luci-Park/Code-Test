
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<long long> before, after;
    while(N--){
        int n;
        cin >> n;
        before.push_back(n);
        after.push_back(n);
    }
    sort(after.begin(), after.end());
    after.erase(unique(after.begin(), after.end()), after.end());
    for(int i:before){
        cout << lower_bound(after.begin(), after.end(), i) - after.begin() <<" ";
    }
    return 0;
}
