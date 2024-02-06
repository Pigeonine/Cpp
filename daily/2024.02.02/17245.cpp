#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<long long> arrs;

int search(int start, int end, long long target)
{
    long long st = start, ed = end;
    long long mid,result;
    long long cou;
    while(st <= ed){
        cou = 0;
        mid = (st + ed)/2;
        //cout << mid << endl;
        for(int i = 0; i < arrs.size(); i++)
        {
            cou += min(mid, arrs[i]);
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
    int n; cin >> n; long long target = 0;
    arrs.resize(n*n);
    for(int i = 0; i < n*n; i++) 
    {
        cin >> arrs[i];
        target += arrs[i];
    }
    target = target/2 + target%2;

    cout << search(0, 10000000, target);

}