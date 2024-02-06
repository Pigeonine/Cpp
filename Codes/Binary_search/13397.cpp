#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> arrs;


int search(int start, int end, int target)
{
    long long st = start, ed = end;
    long long mid,result;
    long long cou;
    while(st <= ed){
        cou = 1;
        mid = (st + ed)/2;
        int pmax = arrs[0], pmin = arrs[0];
        for(int i = 1; i < arrs.size(); i++)
        {
            if(max(pmax, arrs[i]) - min(pmin, arrs[i]) > mid) 
            {
                cou++; pmax = arrs[i]; pmin = arrs[i];
            }
            else 
            {
                pmax = max(pmax, arrs[i]); pmin = min(pmin, arrs[i]);
            }
        }
        if(cou <= target){
            ed = mid-1;
            result = mid;
        }
        else if(cou > target)
        {
            st = mid + 1;
        }
    }
    return result;
}


int main() {
    fastio;
    int n, m; cin >> n >> m;
    arrs.resize(n);

    for(int i = 0; i < n; i++) 
    {
        cin >> arrs[i];
    }

    cout << search(0, 50000000, m);
}