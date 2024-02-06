#include <bits/stdc++.h>

using namespace std;

int main()
{
    while(1){
        int x, y, z;
        cin >> x >> y>> z;
        if(x == 0 || y == 0 || z == 0) break;
        int px = x * x;
        int py = y*y;
        int pz = z * z;
        if(px + py == pz || px + pz == py || py + pz == px)
        {cout << "right\n";}
        else {cout << "wrong\n";}
    }
    return 0;
}