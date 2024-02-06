#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int t, y, m, d; cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> y >> m >> d;
        int sum = 0;
        for(int j = y + 1; j <= 999; j++)
        {
            if(j%3 == 0) sum += 200;
            else sum+= 195;
        }
        
        if(y%3 ==0)
        {
            sum+= 200- 20*(m-1) - d;
        }
        else
        {
            sum+= 195 - (m-1)/2*39 - (m-1)%2*20 - d;
        }
        cout << sum+1 << "\n";
            
    }
    
}