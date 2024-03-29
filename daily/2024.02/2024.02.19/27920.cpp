#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int n; cin >> n;
    if(n % 2 == 0)
    {   cout << "YES" << "\n";
        for(int i = n-2; i >=2; i -= 2) cout << i << ' '; 
        cout << n << ' ';
        for(int i = 1; i < n; i += 2) cout << i << ' ';
        cout << "\n";
        for(int i = 0; i < n/2; i++)
            cout << n - i << ' ' << i + 1 << ' ';
        cout << "\n";
    }
    else{
        cout << "YES" << "\n";
        for(int i = n/2; i >= 1; i--) cout << 2 * i - 1 << ' ';
        cout << n << ' ';
        for(int i = 1; i <= n/2; i++) cout << 2 * i << ' ';
        cout << "\n";
        for(int i = 0; i < n/2; i++) cout << n - i << ' ' << i + 1 << ' ';
        cout << n/2 + 1 << "\n";
    }
}