#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int n; cin >> n;
    long long fir = 0, sec = 1;
    for(int i = 0; i < n-1; i++)
    {
        long long temp = sec;
        sec += fir; fir = temp;
    }
    cout << sec;
}