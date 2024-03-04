#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int n, k,temp, counts = 0;
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        while(temp % 2 == 0)
        {
            counts++; temp /= 2;
        }
    }


    if(counts >= k) cout << 1;
    else cout << 0;
}