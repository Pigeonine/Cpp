#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define MOD_VAL 1000000007

using namespace std;

int main() {
    fastio;
    int n; cin >> n;
    long long res = 0, temp, pre_sum = 0;
    for(int i = 0; i < n-1; i++)
    {
        cin >> temp; pre_sum = ((pre_sum+1) * temp) % MOD_VAL;
        res = (res + pre_sum) % MOD_VAL;
    }
    cout << res;
}