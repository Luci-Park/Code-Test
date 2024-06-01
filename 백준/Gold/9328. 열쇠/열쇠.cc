#include <iostream>
#include <queue>
using namespace std;

struct comp
{
    int y, x;
    char val;
    comp() {}
    comp(int y, int x, char v)
        :y(y), x(x), val(v) {}
    bool operator()(comp a, comp b)
    {
        if (a.val == '.') return false;
        if (b.val == '.') return true;
        return a.val > b.val;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    char map[100][100];
    bool visit[100][100];
    int dy[] = { 0, 1, 0, -1 };
    int dx[] = { 1, 0, -1, 0 };
    while (t--)
    {
        int h, w; cin >> h >> w;
        bool keys[26] = {};
        priority_queue<comp, vector<comp>, comp> pq;
        queue<comp> q;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
                visit[i][j] = false;
                if (map[i][j] != '*' && (i == 0 || j == 0 || i == h - 1 || j == w - 1))
                {
                    if (isupper(map[i][j])) q.emplace(i, j, map[i][j]);
                    else pq.emplace(i, j, map[i][j]);
                    visit[i][j] = true;
                }
            }
        }
        string str; cin >> str;
        if (str != "0")
            for (int i = 0; i < str.size(); i++)
                keys[str[i] - 'a'] = true;
        int docs = 0;
        int qsize;
        do
        {
            while (!pq.empty())
            {
                comp c = pq.top(); pq.pop();
                if (c.val == '$') docs += 1;
                if (islower(c.val)) keys[c.val - 'a'] = true;
                for (int i = 0; i < 4; i++)
                {
                    int ny = c.y + dy[i], nx = c.x + dx[i];
                    if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                    if (map[ny][nx] == '*' || visit[ny][nx]) continue;
                    if (isupper(map[ny][nx]) && !keys[map[ny][nx] - 'A']) 
                        q.emplace(ny, nx, map[ny][nx]);
                    else 
                        pq.emplace(ny, nx, map[ny][nx]);
                    visit[ny][nx] = true;
                }
            }
            qsize = q.size();
            int s = qsize;
            while (s--)
            {
                comp c = q.front(); q.pop();
                if (keys[c.val - 'A']) pq.emplace(c);
                else q.emplace(c);
            }
        } while (q.size() != qsize);

        cout << docs << "\n";
        }

    return 0;
}
