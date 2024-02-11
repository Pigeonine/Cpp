#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<long long> arrs;

long long n, m,temp;

long long bsearch(long long start, long long end, long long target)
{
    long long st = start, ed = end;
    long long mid,result;
    long long cou;
    while(st <= ed){
        cou = m;
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
     cin >> n >> m;
    
    for(int i = 0; i < m; i++)
    {
        cin >> temp;
        arrs.push_back(temp);
    }
    if(n <= m) cout << n;
    else{
        long long ex = bsearch(0, n * arrs[0], n);
        long long re_sum = 0;
        for(int i = 0; i < m; i++)
            re_sum += ex/arrs[i] + 1;
        for(int i = m-1; i >=0; i--)
        {
            if(ex%arrs[i] == 0)
            {
                if(re_sum == n) 
                {
                    cout << i+1;
                    break;
                }
                else re_sum--;
            }
        }
        
    }
}