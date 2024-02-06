#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<tuple<int, int, char>> arrs;

int main() {
    fastio;
    int n, m, a, b; char c; cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        arrs.push_back({b,a,c});
    }
    sort(arrs.begin(), arrs.end());

    for(int i = 0; i < m; i++)
        cout << get<2>(arrs[i]);
}