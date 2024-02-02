#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<long long> a_arrs, b_arrs, c_arrs, d_arrs, cd_sum;
int main() {
    fastio;
    long long n, a, b, c, d; cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        a_arrs.push_back(a); b_arrs.push_back(b); c_arrs.push_back(c); d_arrs.push_back(d);
    }
    
    long long count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cd_sum.push_back(c_arrs[i] + d_arrs[j]);
        }
    }
    sort(cd_sum.begin(), cd_sum.end());
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            count+= upper_bound(cd_sum.begin(),cd_sum.end(), -(a_arrs[i]+b_arrs[j])) - lower_bound(cd_sum.begin(),cd_sum.end(), -(a_arrs[i]+b_arrs[j]));
        }
    }
    cout << count;
}