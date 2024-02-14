#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<double> arrs;

int main() {
    fastio;
    int n,a,b; cin >> n;
    double sums = 0.0;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        arrs.push_back((double) a/b);
        sums += arrs[i];
    }
    sort(arrs.begin(), arrs.end());
    cout.precision(10); cout << fixed;
    cout << arrs[0] << ' ' << arrs[n-1] << ' ' << sums;
}