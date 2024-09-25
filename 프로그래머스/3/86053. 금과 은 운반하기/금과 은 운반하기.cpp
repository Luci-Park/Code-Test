#include <string>
#include <vector>

using namespace std;

bool isPossible(long long time, int a, int b, vector<int>& g, vector<int>& s, vector<int>& w, vector<int>& t)
{
    long long gsum = 0, ssum = 0, bothsum = 0;
    for (int i = 0; i < g.size(); i++)
    {
        if (time < t[i]) continue;
        long long move = (time - t[i]) / (t[i] * 2) + 1;

        long long gi = g[i], si = s[i], wi = w[i], maxMove = wi * move;
        
        long long gold = min(gi, maxMove);
        long long silver = min(si, maxMove);
        long long both = min(gi + si, maxMove);

        gsum += gold;
        ssum += silver;
        bothsum += both;

        if (gsum >= a && ssum >= b && bothsum >= a + b) return true;
    }

    return gsum >= a && ssum >= b && bothsum >= a + b;
}

long long maxTime(vector<int>& g, vector<int>& s, vector<int>& w, vector<int>& t)
{
    long long time = 0;
    for (int i = 0; i < g.size(); i++)
    {
        long long gi = g[i], si = s[i], wi = w[i], ti = t[i];
        time = max(time, (gi + si) / wi * ti * 2);
    }
    return time;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) 
{
    long long answer;
    unsigned long long lo = 1, hi = maxTime(g, s, w, t);
    
    while (lo <= hi)
    {
        unsigned long long mid = (lo + hi) / 2;
        if (isPossible(mid, a, b, g, s, w, t))
        {
            answer = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return answer;
}