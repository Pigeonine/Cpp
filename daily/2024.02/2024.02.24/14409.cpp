#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int n, x, p1, p2, p3, sums = 0; cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> p1 >> p2;
        if(max(p1,p2) - min(p1,p2) > x) 
        {
            cin >> p3; sums += p3;
        }
        else sums += max(p1,p2);
    }
    cout << sums;
}