#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> arrs;

long long bsearch(long long start, long long end, int target)
{
    long long st = start, ed = end;
    long long mid,result;
    long long cou;
    while(st <= ed){
        cou = 0;
        mid = (st + ed)/2;
        for(int i = 0; i < arrs.size(); i++)
        {
            cou += mid/arrs[i];
        }
        if(cou >= target){
            ed = mid-1;
            result = mid;
        }
        else if(cou < target)
        {
            st = mid + 1;
        }
    }
    return result;
}


int main() {
    fastio;
    int n, m,t; cin >> n >> m;
    int mint = 1000000001;
    arrs.resize(n);
    for(int i = 0; i < n; i++) 
    {
        cin >> arrs[i];
        mint = min(mint, arrs[i]);
    }
    cout << bsearch(1,(long long) mint * (long long) m, m);
}