#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, cnt = 0; cin >> n;
    vector<int> nums(n), incNums(n), decNums(n), temp(n,1000);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
        auto it = lower_bound(temp.begin(), temp.begin() + cnt, nums[i]);
        int idx = it - temp.begin();
        if(idx == cnt) temp[cnt++] = nums[i];
        else temp[idx] = nums[i];
        incNums[i] = cnt;
    }
    cnt = 0; temp[0] = 1000;
    for(int i = n - 1; i >= 0; --i) {
        auto it = lower_bound(temp.begin(), temp.begin() + cnt, nums[i]);
        int idx = it - temp.begin();
        if(idx == cnt) temp[cnt++] = nums[i];
        else temp[idx] = nums[i];
        decNums[i] = cnt;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(incNums[i] + decNums[i] > ans){
            ans = incNums[i] + decNums[i];
        }
    }
    cout << ans - 1;
    return 0;
}