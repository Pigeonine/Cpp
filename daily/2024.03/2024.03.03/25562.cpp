#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int n; cin >> n;
    cout << n * (n-1) / 2 << "\n";
    for(int i = 0; i < n; i++)
        cout << (int)pow(2,i) << ' ';
    cout << "\n";
    cout << n-1 << "\n";
    for(int i = 1; i <= n; i++) cout << i << ' ';
}