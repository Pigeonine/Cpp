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
        cou = 0;
        mid = (st + ed)/2;
        for(int i = 0; i < arrs.size()-1; i++)
        {
            if((arrs[i+1] - arrs[i]) % mid == 0)
            {
                cou += (arrs[i+1] - arrs[i])/mid - 1;
            }
            else{
                cou += (arrs[i+1] - arrs[i])/mid;
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
    int n, m, l; cin >> n >> m >> l;
    arrs.resize(n+2);
    arrs[0] = 0;
    for(int i = 1; i <= n; i++) cin >> arrs[i];
    arrs[n+1] = l;
    sort(arrs.begin(), arrs.end());
    cout << search(1,l, m);
    
}