#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int n, t = 0;
    while(cin >> n)
    {
        t++;
        if(n == 0) break;
        vector<int> arrs(n);
        int sums = 0, counts = 0;
        for(int i = 0; i < n; i++) 
        {
            cin >> arrs[i]; sums += arrs[i];
        }
        int res = sums/n;
        for(int i = 0; i < n; i++)
        {
            if(arrs[i] < res) counts += res - arrs[i];
        }
        cout << "Set #" << t << "\n" << "The minimum number of moves is " << counts <<'.' << "\n" << "\n";
    }
}