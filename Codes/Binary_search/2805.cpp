#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> arrs;

int bsearch(int start, int end, int target)
{
    long long st = start, ed = end;
    long long mid,result;
    long long cou;
    while(st <= ed){
        cou = 0;
        mid = (st + ed)/2;
        for(int i = 0; i < arrs.size(); i++)
        {
            cou += max(arrs[i]-mid,(long long)0);
        }
        if(cou >= target){
            st = mid+1;
            result = mid;
        }
        else if(cou < target)
        {
            ed = mid - 1;
        }
    }
    return result;
}


int main() {
    fastio; 
    int n, m,temp, max_h = 0; cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
         cin >> temp; arrs.push_back(temp);
         max_h = max(max_h, temp);
    }
    cout << bsearch(0, max_h, m);

}