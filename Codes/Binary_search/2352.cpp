#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int arrays[40001];
int inc_arrs[40001];

int cur_max = 1;

int main() {
    fastio;
    int n;
    cin >> n;
    for(int i =1; i <= n; i++)
    {
        cin >> arrays[i];
    }
    
    inc_arrs[1] = arrays[1];
    
    for(int i = 2; i <= n; i++)
    {
        int temp = lower_bound(inc_arrs+1,inc_arrs+cur_max+1, arrays[i]) - inc_arrs;
        if(temp > cur_max) 
        {
            cur_max++;
            inc_arrs[cur_max] = arrays[i];
            //cout <<"equal " <<  cur_max << ' ' << arrays[i] << ' ' << endl;
        }
        else
        {
            if(inc_arrs[temp] > arrays[i]) 
            {
                inc_arrs[temp] = arrays[i];
                //cout << "change " << temp << ' ' << arrays[i] << ' ' << cur_max << endl;
                
            }
        }
    }
    cout << cur_max;
}
