#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;


int main() {
    fastio;
    int n; cin >> n;
    if(n == 0) cout << 1;
    else if(n < 0) cout << 32;
    else
    {
        int res = 0;
        while(n > 0)
        {
            res++; n /= 2;
        }
        cout << res;
    }
    
}