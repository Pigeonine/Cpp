#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define MINSUM -2000000000


using namespace std;


int arrs[1001];

tuple<int,int,int> find(int st, int ed)
{
    if(st >= ed) return {st, ed, arrs[st]};
    int mid = (st+ed)/2;
    tuple<int,int,int> left = find(st, mid), right = find(mid+1,ed);
    int lmax = MINSUM, rmax = MINSUM, ltemp = 0, rtemp = 0, lind, rind;
    for(int i = mid; i >= st; i--)
    {
        ltemp +=arrs[i]; lmax = max(lmax, ltemp);
        if(ltemp >= lmax){
            lmax = ltemp; lind = i;
        }
    }
    for(int i = mid + 1; i <= ed; i++)
    {
        rtemp += arrs[i];
        if(rtemp >= rmax)
        {
            rmax = rtemp; rind = i;
        }
    }
    int midmax = rmax + lmax;
    if(get<2>(left) >= get<2>(right) && get<2>(left) >= midmax)
    {
        return left;
    }
    else if(get<2>(right) >= get<2>(left) && get<2>(right) >= midmax){
        return right;
    }
    else{
        return {lind, rind, midmax};
    }
}


int main() {
    fastio;
    int t; cin >> t;
    for(int j = 0; j < t; j++)
    {
        int n; cin >> n;
        for(int i = 1; i <= n; i++) cin >> arrs[i];
        tuple<int,int,int> res = find(1,n);
        cout << get<2>(res) << "\n";
    }
    
}