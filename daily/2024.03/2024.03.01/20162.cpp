#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int arrs[1000];
vector<int> partial;
int sums[1000];

int main() {
    fastio;
    int n, res = 0; cin >> n;
    for(int i = 0; i < n; i++) {cin >> arrs[i]; partial.push_back(arrs[i]);}
    sort(partial.begin(), partial.end());
    for(int i = 0; i < n; i++)
    {
        int ord = lower_bound(partial.begin(),partial.end(), arrs[i]) - partial.begin();
        //cout << arrs[i] << ' ' << ord << endl;
        for(int j = 0; j < ord; j++)
            if(sums[j] != 0)
                sums[ord] = max(sums[ord], sums[j] + arrs[i]);
        sums[ord] = max(sums[ord], arrs[i]);
        res = max(res, sums[ord]);
        //cout << res << ' ' << sums[ord] << endl << endl;
    }
    cout << res;
}