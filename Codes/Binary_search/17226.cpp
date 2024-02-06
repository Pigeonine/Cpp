#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> arrs;

int bsearch(int start, int end)
{
    long long st = start, ed = end;
    long long mid,result;
    long long cou;
    while(st <= ed){
        cou = 0;
        mid = (st + ed)/2;
        bool posb = true;
        if(arrs[1] - arrs[0] > mid || arrs[arrs.size()-1] - arrs[arrs.size()-2] > mid) {
            posb = false;
        }
        else {
            for(int i = 2; i < arrs.size()-1; i++)
            {
               if(arrs[i] - arrs[i-1] > 2 * mid)
               {
                    posb = false; break;
                }
            }
        }
        if(posb){
            ed = mid-1;
            result = mid;
        }
        else
        {
            st = mid + 1;
        }
    }
    return result;
}

int main() {
    fastio;
    int n, m,x; cin >> n >> m;
    arrs.push_back(0);
    for(int i = 0; i < m; i++)
    {
        cin >> x; arrs.push_back(x);
    }
    arrs.push_back(n);
    cout << bsearch(1, 100000);
}