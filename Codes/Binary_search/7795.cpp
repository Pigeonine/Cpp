#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> a_arrs;
vector<int> b_arrs;

int main() {
    fastio;
    int t,n,m,a,b; cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n >> m;
        for(int j = 0; j < n; j++)
        {
            cin >> a; a_arrs.push_back(a);
        }
        for(int j = 0; j < m; j++)
        {
            cin >> b; b_arrs.push_back(b);
        }
        sort(a_arrs.begin(), a_arrs.end());
        sort(b_arrs.begin(), b_arrs.end());
        int count = 0;
        for(int j = 0; j < n; j++)
        {
            count += lower_bound(b_arrs.begin(), b_arrs.end(), a_arrs[j]) - b_arrs.begin();
        }
        a_arrs.clear();
        b_arrs.clear();
        cout << count << "\n";
    }   
}