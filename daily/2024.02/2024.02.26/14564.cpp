#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int n, m, a, x, mid; cin >> n >> m >> a;
    mid = m/2 + 1;
    while(cin >> x)
    {
        if (x== mid) {
            cout << 0 << "\n";
            break;
        }

        a = (a + x - mid-1 + n) % n + 1;
        cout << a << "\n";
    }
}