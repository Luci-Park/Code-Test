    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    #include <climits>
    using namespace std;
    
    int graph[16][16];
    int n;
    int sum = 0, hori = 0, verti = 1, diag = 2;    
    int dy[3] = { 0, 1, 1 };
    int dx[3] = { 1, 0, 1 };

    bool validLine(int y, int x) {
        return y < n && x < n && !graph[y][x];
    }

    bool canDiag(int ly, int lx, int ry, int rx) {
        for (int i = 0; i < 3; ++i) {
            int y = ry + dy[i], x = rx + dx[i];
            if (!validLine(y, x)) return false;
        }
        return true;
    }

    bool canHorz(int ly, int lx, int ry, int rx) {
        if (ly != ry && lx == rx) return false;
        int y = ry + dy[hori], x = rx + dx[hori];
        return validLine(y, x);
    }

    bool canVert(int ly, int lx, int ry, int rx) {
        if (ly == ry && lx != rx) return false;
        int y = ry + dy[verti], x = rx + dx[verti];
        return validLine(y, x);
    }


    void dfs(int ly, int lx, int ry, int rx) {
        if (ry == n - 1 && rx == n - 1) {
            sum += 1;
        }
        else {
            if (canDiag(ly, lx, ry, rx)) {
                dfs(ry, rx, ry + dy[diag], rx + dx[diag]);
            }
            if (canHorz(ly, lx, ry, rx)) {
                dfs(ry, rx, ry + dy[hori], rx + dx[hori]);
            }
            if (canVert(ly, lx, ry, rx)) {
                dfs(ry, rx, ry + dy[verti], rx + dx[verti]);
            }
        }
    }


    int main()
    {
        ios_base :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> graph[i][j];
            }
        }

        dfs(0, 0, 0, 1);


        cout << sum;

        return 0;
    }
