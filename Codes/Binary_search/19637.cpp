#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<string> names;
vector<int> names_spec;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    names.resize(n); names_spec.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> names[i] >> names_spec[i];
    }
    for(int i = 0; i < m; i++)
    {
        int temp; cin >> temp;
        cout << names[lower_bound(names_spec.begin(), names_spec.end(), temp)-names_spec.begin()] << "\n";
    }
}