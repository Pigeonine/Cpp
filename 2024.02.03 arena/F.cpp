#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> sockets;
vector<int> elec;

int main() {
    fastio;
    int n,m,k; cin >> n >> k >> m;
    sockets.resize(n); elec.resize(m);
    for(int i = 0; i < n; i++) cin >> sockets[i];
    for(int i = 0; i < m; i++) cin >> elec[i];
}