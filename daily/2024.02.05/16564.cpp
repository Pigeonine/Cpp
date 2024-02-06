#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> arrs;

vector<int> lan_len;

int search(int start, int end, int target)
{
    long long st = start, ed = end;
    long long mid,result;
    long long cou;
    while(st <= ed){
        cou = 0;
        mid = (st + ed)/2;
        for(int i = 0; i < arrs.size(); i++)
        {
            if(mid > arrs[i]) cou += mid - arrs[i];
        }
        if(cou <= target){
            st = mid+1;
            result = mid;
        }
        else if(cou > target)
        {
            ed = mid - 1;
        }
    }
    return result;
}


int main() {
    fastio;
    int n, k, temp, maxd = 0; cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> temp; arrs.push_back(temp); maxd = max(maxd, temp);
    }
    cout << search(1, maxd + k, k);
    
}