#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int arrs[100000];

int main() {
    fastio;
    int n, k, sums = 0, temp, maxd = -2000000000; cin >> n >> k;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> temp; sums += temp; arrs[i] = sums;
    }

    for(int i = k; i <= n; i++)
        maxd = max(maxd, arrs[i] - arrs[i-k]);
    cout << maxd;
}