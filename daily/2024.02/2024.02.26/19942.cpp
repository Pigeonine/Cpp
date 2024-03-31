#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

struct nuts
{
    int protein;
    int fat;
    int carbohydrate;
    int vitamin;
    int price;
};

struct nuts arrs[15];
int mins = 2000000000; int memb;
int n,mp, mf, ms, mv, p,f,s,v,c;
void dfs(int p, int f, int s, int v, int c, int ind, int members)
{   
    if(p >= mp && f >= mf && s >= ms && v >= mv)
    {
        if(c < mins)
        {
            mins = c; memb = members;
            return;
        }
    }
    if(ind == n) return;
    

    dfs(p + arrs[ind].protein, f + arrs[ind].fat, s + arrs[ind].carbohydrate, v + arrs[ind].vitamin, c + arrs[ind].price, ind + 1,  members + (1 << (n-1-ind)));
    dfs(p,f,s,v,c,ind+1,members);
    return;

}

int main() {
    fastio;
     cin >> n;
    
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0; i < n; i++)
    {
        cin >> p >> f >> s >> v >> c;
        arrs[i] = {p,f,s,v,c};
    }
    
    dfs(0, 0, 0, 0, 0, 0,0);
    if(mins == 2000000000)
    {
        cout << -1; return 0;
    }
    cout << mins << "\n";
    for(int i = 0; i < n; i++)
    {
        if((1 << (n-1-i)) & memb) cout << i + 1 << ' ';
    }
}

