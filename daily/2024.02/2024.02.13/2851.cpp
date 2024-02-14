#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int arrs[10];

int main() {
    fastio;
    for(int i = 0; i < 10; i++) cin >> arrs[i];
    int sums = arrs[0];
    for(int i = 1; i < 10; i++)
    {
        if(abs(sums + arrs[i] - 100) <= abs(sums - 100))
            sums += arrs[i];
        else break;
    }
    cout << sums;
}