#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> arrs;

int main() {
    fastio;
    int t,n,m,temp; cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            cin >> temp; arrs.push_back(temp);
        }
        sort(arrs.begin(), arrs.end());
        cin >> m;
        for(int j = 0; j < m; j++)
        {
            cin >> temp;
            if(binary_search(arrs.begin(), arrs.end(), temp)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        arrs.clear();
    }
}