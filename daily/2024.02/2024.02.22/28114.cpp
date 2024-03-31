#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<pair<int, string>> d;
vector<int> years;

int main() {
    fastio;
    int year, p; string n;
    for(int i = 0; i < 3; i++) {
        cin >> p >> year >> n;
        years.push_back(year % 100);
        d.push_back({p, n});
    }
    sort(years.begin(), years.end());
    sort(d.begin(), d.end()); reverse(d.begin(), d.end());
    for(auto i : years) cout << i; 
    cout << "\n";
    for(auto i : d) cout << i.second[0];

}