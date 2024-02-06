#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;
vector<int> arrs;
int n, m;
long long bsearch(int start, int end, long long target)
{
    long long st = start, ed = end;
    long long mid,result;
    long long cou;
    
    while(st <= ed){
        cou = 0;
        mid = (st + ed)/2;
        for(int i = 0; i < m; i++)
        {
            if(arrs[i] % mid == 0)
            {
                cou += arrs[i]/mid;
            }
            else{
                cou += arrs[i]/mid + 1;
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
    cin >> n >> m;
    arrs.resize(m);
    for(int i = 0; i < m; i++) cin >> arrs[i];
    long long temp = bsearch(1, 1000000000, n);
    cout << temp;
}