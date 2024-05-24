#include <string>
#include <vector>
#include <list>
#include <climits>
using namespace std;

int dp[300000][2] = {0, };
list<int> graph[300000];
int n;
void dfs(vector<int>& sales, int node)
{
    int childSum = 0;
    bool exists = false;
    for(int i : graph[node])
    {
        dfs(sales, i);
        if(dp[i][1] < dp[i][0]) exists = true;
        childSum += min(dp[i][0], dp[i][1]);
    }
    dp[node][1] = sales[node] + childSum;
    if(exists || graph[node].empty())
        dp[node][0] = childSum;
    else
    {
        int minN = INT_MAX;
        for(int i: graph[node])
        {
            int newNum = childSum - dp[i][0] + dp[i][1];
            if(newNum < minN) minN = newNum;
        }
        dp[node][0] = minN;
    }
}
int solution(vector<int> sales, vector<vector<int>> links) {
    n = sales.size();
    for(int i =0; i < links.size(); i++)
    {
        graph[links[i][0] - 1].push_back(links[i][1] - 1);
    }
    dfs(sales, 0);    
    return min(dp[0][0], dp[0][1]);
}