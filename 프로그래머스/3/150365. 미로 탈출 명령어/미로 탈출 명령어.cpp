#include <string>
#include <vector>

using namespace std;

int length(int y, int x, int r, int c)
{
    return abs(y - r) + abs(x - c);
}

string solution(int n, int m, int y, int x, int r, int c, int k) 
{
    string str = "";
    while (k)
    {
        --k;
        if (y < n && length(y + 1, x, r, c) <= k) { ++y; str += 'd'; }
        else if (x > 1 && length(y, x - 1, r, c) <= k) { --x; str += 'l'; }
        else if (x < m && length(y, x + 1, r, c) <= k) { ++x; str += 'r'; }
        else if (y > 1 && length(y - 1, x, r, c) <= k) { --y; str += 'u'; }
        else return "impossible";
    }
    return str;
}