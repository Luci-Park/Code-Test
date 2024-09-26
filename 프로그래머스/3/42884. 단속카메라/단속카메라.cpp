#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {

    sort(routes.begin(), routes.end(), comp);
    int answer = 1;

    int currentPoint = routes[0][1];

    for (int i = 1; i < routes.size(); i++)
    {
        if (routes[i][0] > currentPoint)
        {
            answer += 1;
            currentPoint = routes[i][1];
        }
    }
    return answer;
}