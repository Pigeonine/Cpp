#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int arrs[16][2], dp[17];


int main() {
    fastio;
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arrs[i][0] >> arrs[i][1];
    
    int maxd = 0;
    for(int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i], dp[i-1]);
        if(i + arrs[i][0] <= n+1)
            dp[i + arrs[i][0]] = max(dp[i + arrs[i][0]], dp[i] + arrs[i][1]);
    }
    dp[n+1] = max(dp[n+1],dp[n]);
    cout << dp[n+1];
}