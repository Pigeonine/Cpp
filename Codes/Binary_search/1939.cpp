#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int parray[100000];
vector<tuple<int,int,int>> bridges;

int parent(const int &target)
{
    if(target != parray[target]) return parray[target] = parent(parray[target]);
    return target;
}

void init(const int &n)
{
    for(int i = 0; i < n; i++) parray[i] = i;
}

void uni(const int &a, const int &b)
{
    int a_p = parent(a); int b_p = parent(b);
    if(a_p > b_p)
    {
        parray[a_p] = b_p;
    }
    else if(a_p < b_p)
    {
        parray[b_p] = a_p;
    }

}

int main() {
    fastio;
    int n, m,a,b,c, comp1, comp2; cin >> n >> m;
    init(n);
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        bridges.push_back({c,a,b});
    }
    cin >> comp1 >> comp2;
    sort(bridges.begin(), bridges.end());

    reverse(bridges.begin(), bridges.end());

    for(int i = 0; i < bridges.size(); i++)
    {
        uni(get<1>(bridges[i]), get<2>(bridges[i]));
        if(parent(comp1) == parent(comp2)) 
        {
            cout << get<0>(bridges[i]);
            break;
        }
    }
}