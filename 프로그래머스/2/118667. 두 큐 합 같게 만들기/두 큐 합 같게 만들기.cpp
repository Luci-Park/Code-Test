#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int solution(vector<int> queue1, vector<int> queue2) {
    ll sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    ll sum2 = accumulate(queue2.begin(), queue2.end(), 0);
    queue<int> q1;
    queue<int> q2;
    for(int i =0; i < queue1.size(); i++)
        q1.push(queue1[i]);
    for(int i =0; i < queue2.size(); i++)
        q2.push(queue2[i]);
    int size = queue1.size() + queue2.size();
    int answer = 0;
    while(sum1 != sum2 && answer < size + 5)
    {
        if(sum1 < sum2)
        {
            sum2 -= q2.front();
            sum1 += q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        else if(sum1 > sum2)
        {
            sum1 -= q1.front();
            sum2 += q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        answer += 1;
    }
    if(answer >= size + 5)answer = -1;
    return answer;
}