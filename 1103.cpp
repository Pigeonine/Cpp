#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int arrs[50][50]{};

int r_d[4] = {1, 0, -1, 0};
int c_d[4] = {0, 1, 0, -1};
int n, m; 
set<pair<int,int>> start;

int bfs(pair<int,int> st_point, set<pair<int,int>> pasts)
{
    //cout << st_point.first << ' ' << st_point.second << endl;
    int max_counts = 0;
    for(int j = 0; j < 4; j++)
    {
        int next_r = st_point.first + arrs[st_point.first][st_point.second]*r_d[j],
        next_c = st_point.second + arrs[st_point.first][st_point.second]*c_d[j];
        if(next_r >=0 && next_c >= 0 && next_r < n && next_c < m)
        {
            if(arrs[next_r][next_c] == 0) continue;

            if(pasts.count(make_pair(next_r,next_c))) return -1;
            set<pair<int,int>> temp(pasts);
            temp.insert(make_pair(next_r,next_c));
            int res = bfs(make_pair(next_r,next_c), temp);
            if(res == -1) return -1;
            else max_counts = max(max_counts, res);
        }
    }
    return 1+max_counts;
}


int main() {
    fastio;
    cin >> n >> m;
    string s;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        for(int j = 0; j < m; j++)
        {
            if(s[j] == 'H') arrs[i][j] = 0;
            else arrs[i][j] = s[j] - '0';
        }
    }
    start.insert(make_pair(0,0));
    

    cout << bfs(make_pair(0,0), start);
    
    
}