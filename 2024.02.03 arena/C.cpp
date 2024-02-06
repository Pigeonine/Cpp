#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int a_arrs[64][64], b_arrs[64][64];
bool tiles[64][64]{};

int r_dir[4] = {-1,0,1,0};
int c_dir[4] = {0,1,0,-1};

int main() {
    fastio;
    int h, w, r, c, d; string a, b;
    cin >> h >> w >> r >> c >> d;
    for(int i = 0; i < h; i++)
    {
        cin >> a;
        for(int j = 0; j < w; j++)
        {
            a_arrs[i][j] = a[j] - '0';
            //cout << a_arrs[i][j];
        }
        //cout << endl;
    }

    for(int i = 0; i < h; i++)
    {
        cin >> b;
        for(int j = 0; j < w; j++){
            b_arrs[i][j] = b[j] - '0';
            //cout << b_arrs[i][j];
        }
        //cout << endl;
    }
    int rep_r = -1, rep_c = -1;
    long long total_rep = 0;
    long long rep = 0;
    long long rep_count = 0;
    while(r >= 0 && r < h && c >= 0 && c < w)
    {
        total_rep++;
        if(!tiles[r][c])
        {
            tiles[r][c] = true;
            d = (d + a_arrs[r][c]) % 4;
            rep = total_rep;
            rep_count = 0;
        }
        else
        {
            d = (d + b_arrs[r][c]) % 4;
            rep_count++;
        }
        if(rep_count > 10000000) break;
        r += r_dir[d]; c += c_dir[d];
    }

    cout << rep;
}