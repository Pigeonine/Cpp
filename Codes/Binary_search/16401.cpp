#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> arrs;

long long search(int start, int end, int target)
{
    long long st = start, ed = end;
    long long mid,result;
    long long cou;
    
    while(st <= ed){
        cou = 0;
        mid = (st + ed)/2;
        for(int i = 0; i < arrs.size(); i++)
        {
            cou += arrs[i]/mid;
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
    int m, n;
    long long sum = 0;
    cin >> m >> n;
    arrs.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> arrs[i];
        sum += arrs[i];
    }
    if(sum < m) {cout << 0; return 0;}
    cout << search(1,1000000000, m);
}