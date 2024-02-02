#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int n;
    cin >> n;
    if(n == 1) 
        cout << 1 << "\n" << 1 << ' ' << 1;
    else
    {
        cout << 2*n-2<< "\n";
        for(int i = 1; i <= n; i++)
            cout << 1 << ' ' << i << "\n";
        for(int i = 2; i <= n-1; i++)
            cout << n << ' ' << i<< "\n";
    }
    
}