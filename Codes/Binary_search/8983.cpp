#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<long long> hunt_p;
vector<pair<long long,long long>> animals;

int main() {
    fastio;
    long long m, n, l, x,y; cin >> m >> n >> l;
    hunt_p.resize(m);
    for(int i =0; i < m; i++) cin >> hunt_p[i];
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        animals.push_back(make_pair(x,y));
    }
    sort(hunt_p.begin(), hunt_p.end());
    long long cou = 0;
    for(int i = 0; i < n; i++)
    {
        if(animals[i].second > l) continue;

        long long low_h = animals[i].first -(l - animals[i].second), high_h = animals[i].first + (l - animals[i].second);
        long long low_index = lower_bound(hunt_p.begin(),hunt_p.end(),low_h)-hunt_p.begin();
        //cout << i << ' ' << animals[i].first << ' ' << animals[i].second << ' ' << low_h << ' ' << high_h << ' ' << low_index << ' ' << hunt_p[low_index] << "\n";
        if(low_index == m) continue;
        
        if(hunt_p[low_index] <= high_h) cou++;
    }
    cout << cou;
}