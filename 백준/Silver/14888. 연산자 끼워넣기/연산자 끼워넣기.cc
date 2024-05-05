#include <iostream>

using namespace std;
long minNum = 2000000000;
long maxNum = -2000000000;
int N;
int nums[11];
int exps[4] = {0, };
void dfs(int depth, long sum)
{
    if(depth == N)
    {
        if(sum < minNum) minNum = sum;
        if(sum > maxNum) maxNum = sum;
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        if(exps[i] == 0) continue;
        long nsum = sum;
        if(i == 0) nsum += nums[depth];
        if(i == 1) nsum -= nums[depth];
        if(i == 2) nsum *= nums[depth];
        if(i == 3) nsum /= nums[depth];
        exps[i] -= 1;
        dfs(depth + 1, nsum);
        exps[i] += 1;
    }
}
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> nums[i];
    for(int i =0; i < 4; i++)
        cin >> exps[i];
    dfs(1, nums[0]);
    cout << maxNum <<"\n" << minNum;
    
    return 0;
}