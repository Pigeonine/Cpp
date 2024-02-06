#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> arrs[20001];
bool barrs[20001]{};

int main() {
    fastio;
    int n, q, m,temp; cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        cin >> m;
        for(int j = 0; j < m; j++)
        {
            cin >> temp;
            arrs[i].push_back(temp);
        }

    }
}