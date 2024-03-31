#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <cmath>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define LGM 17
#define NMAX 100001

using namespace std;

tuple<int,int,int> parents[LGM+1][NMAX]; // fir: parents, sec : min, thi : max
int depths[NMAX];
bool visited[NMAX];
int n, a, b, c; 
vector<pair<int,int>> lines[NMAX]; //first : end point, second : cost

void dfs(int point, int dep)
{
    depths[point] = dep; visited[point] = true;
    for(auto i : lines[point])
    {
        if(!visited[i.first])
        {
            parents[0][i.first] = {point, i.second, i.second};
            dfs(i.first, dep+1);
        }
    }
}

void bfs(int start)
{

}

void find_parents()
{
    for(int k = 1; k <= LGM; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            tuple<int,int,int> fir = parents[k-1][i];
            tuple<int,int,int> sec = parents[k-1][get<0>(fir)];
            parents[k][i] = {get<0>(sec),min(get<1>(fir), get<1>(sec)) ,max(get<2>(fir), get<2>(sec))};
        }
    }
}

pair<int,int> lca(int a, int b)
{
    int mind = 1000001, maxd = 0;
    if(depths[a] > depths[b])
    {
        int temp = a;
        a = b;
        b = temp;
    }

    for(int i = LGM; i >= 0; i--)//matching depths
    {   
        if(depths[b] - depths[a] >= (1 << i))
        {   
            mind = min(mind, get<1>(parents[i][b]));
            maxd = max(maxd, get<2>(parents[i][b]));
            b = get<0>(parents[i][b]);
        }
    }

    if(a == b) return make_pair(mind, maxd);

    for(int i = LGM; i >= 0; i--)
    {
        if(get<0>(parents[i][a]) != get<0>(parents[i][b]))
        {
            mind = min(mind, min(get<1>(parents[i][a]),get<1>(parents[i][b])));
            maxd = max(maxd, max(get<2>(parents[i][a]),get<2>(parents[i][b])));
            a = get<0>(parents[i][a]);
            b = get<0>(parents[i][b]);
        }
    }
    mind = min(mind, min(get<1>(parents[0][a]), get<1>(parents[0][b])));
    maxd = max(maxd, max(get<2>(parents[0][a]), get<2>(parents[0][b])));
    return make_pair(mind, maxd);
}


int main(){
    fastio;
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        cin >> a >> b >> c;
        lines[a].push_back({b,c});lines[b].push_back({a,c});
    }

    dfs(1, 0);
    find_parents();
    
    int m; cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        pair<int,int> res = lca(a,b);
        cout << res.first << ' ' << res.second << "\n";
    }

    

    // for(int k = 0; k <= LGM; k++)
    // {
    //     for(int i = 1; i <= n; i++)
    //     {
    //         cout << get<0>(parents[k][i]) << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(int k = 0; k <= LGM; k++)
    // {
    //     for(int i = 1; i <= n; i++)
    //     {
    //         cout << get<1>(parents[k][i]) << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(int k = 0; k <= LGM; k++)
    // {
    //     for(int i = 1; i <= n; i++)
    //     {
    //         cout << get<2>(parents[k][i]) << ' ';
    //     }
    //     cout << endl;
    // }
}