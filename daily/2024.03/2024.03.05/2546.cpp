#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int cstu[200000], estu[200000];


int main() {
    fastio;
    int t, n, m; cin >> t;
    double avc, ave;
    for(int i = 0; i < t; i++)
    {
        int res = 0;
        cin >> n >> m; avc = 0.0; ave = 0.0;
        for(int j = 0; j < n; j++) {cin >> cstu[j]; avc += cstu[j]; }
        for(int j = 0; j < m; j++) {cin >> estu[j]; ave += estu[j]; }
        avc /= n; ave /= m;
        for(int j = 0; j < n; j++)
            if(cstu[j] < avc && cstu[j] > ave) res++;
        cout << res << "\n";
    }
}