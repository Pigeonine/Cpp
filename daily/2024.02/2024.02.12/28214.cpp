#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int n, k ,p, temp; cin >> n >> k >> p;
    int counts = 0;
    for(int i = 0; i < n; i++)
    {
        int n_c = 0;
        for(int j = 0; j < k; j++)
        {
            cin >> temp;
            if(!temp) n_c++;
        }
        if(n_c < p) counts++;
    }
    cout << counts;
}