#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

bool arrs[501]{};

int main() {
    fastio;
    int n, m, op, s, d; cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> op >> s >> d;
        if(op == 0)
        {
            for(int j = s; j <= d; j++)
            {
                if(arrs[j]) arrs[j] = false;
                else arrs[j] = true;
            }
        }
        else if(op == 1)
        {
            int counts = 0;
            for(int j = s; j <= d; j++)
            {
                if(arrs[j]) counts++;
            }
            cout << counts << "\n";
        }
    }
}