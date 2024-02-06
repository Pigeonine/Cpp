#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> arrs;

int main() {
    fastio;
    int x, n;
    while(cin >> x >> n)
    {
        bool check = false;
        arrs.resize(n);
        for(int i = 0; i < n; i++) cin >> arrs[i];
    
        sort(arrs.begin(), arrs.end());
        for(int i = 0; i < n-1; i++)
        {
            int h_index = upper_bound(arrs.begin()+i+1, arrs.end(), x * 10000000 - arrs[i]) - arrs.begin() - 1;
            if(h_index <= i) continue;

            if(arrs[h_index] == x * 10000000 - arrs[i]) 
            {
                cout << "yes" << ' ' << arrs[i] << ' ' << arrs[h_index] << "\n";
                check = true;
                break;
            }
        }
        if(!check) cout << "danger" << "\n";
        arrs.clear();
    }
}