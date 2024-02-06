#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> arrs;


int main() {
    fastio;
    int n, temp; cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp; arrs.push_back(temp);
    }
    sort(arrs.begin(), arrs.end());
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        int st = 0, ed = n-1;
        while(st < ed)
        {
            if(arrs[st] + arrs[ed] == arrs[i])
            {
                if(st != i && ed != i) 
                {
                    res++; break;
                }
                else if(st == i)
                    st++;
                else if(ed == i)
                    ed--;
            }
            else if(arrs[st] + arrs[ed] > arrs[i]) ed--;
            else if(arrs[st] + arrs[ed] < arrs[i]) st++;
        }
    }
    cout << res;
    
}