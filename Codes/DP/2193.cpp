#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

long long arrs[91][2]; // 0 is the numbers of pinary number ended with 0, 1 is the opposite.

int main() {
    fastio;
    int n; cin >> n;
    arrs[1][1] = 1;
    for(int i = 2; i <= n; i++)
    {
        arrs[i][0] = arrs[i-1][0] + arrs[i-1][1];
        arrs[i][1] = arrs[i-1][0];
    }

    cout << arrs[n][0]+arrs[n][1];

}