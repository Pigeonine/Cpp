#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int tic[3][3]{};

int players[2] = {1,2};

int main() {
    fastio;
    int st,x,y; cin >> st;
    for(int i = 0; i < 9; i++)
    {
        cin >> x >> y;
        x--; y--;
        int p = players[(i+st-1)%2];
        tic[x][y] = p;
        if(tic[x][0] == p && tic[x][1] == p && tic[x][2] == p)
        {
            cout << p; return 0;
        }

        if(tic[0][y] == p && tic[1][y] == p && tic[2][y] == p)
        {
            cout << p; return 0;
        }

        if(x+y == 2)
        {
            if(tic[0][2] == p && tic[1][1] == p && tic[2][0] == p)
            {
                cout << p; return 0;
            }
        }
        if(x == y)
        {
            if(tic[0][0] == p && tic[1][1] == p && tic[2][2] == p)
            {
                cout << p; return 0;
            }
        }
    }
    cout << 0;
}