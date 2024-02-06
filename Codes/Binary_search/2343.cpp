#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> arrs;
int n;

int search(int start, int end, int target)
{
    long long st = start, ed = end;
    long long mid,result;
    long long cou;
    while(st <= ed){
        cou = 1;
        int p_sum = 0;
        mid = (st + ed)/2;
        for(int i = 0; i < n; i++)
        {  
            if(p_sum + arrs[i] > mid)
            {
                cou++; p_sum = arrs[i];
            }
            else p_sum +=arrs[i];
        }
        if(cou > target){
            st = mid+1;
            
        }
        else if(cou <= target)
        {
            ed = mid - 1;
            result = mid;
        }
    }
    return result;
}


int main() {
    fastio;
    int m,temp, sum = 0, maxd = 0; cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        arrs.push_back(temp);
        sum += temp;
        maxd = max(maxd, temp);
    }
    cout << search(maxd, sum, m);
    
    
}