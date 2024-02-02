#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<long long> a_arrs, b_arrs, a_psum, b_psum, a_arr_sum, b_arr_sum;


int main() {
    fastio;
    int t, n, m, temp; cin >> t >> n;
    int a_p=0, b_p=0;
    a_psum.push_back(a_p);
    b_psum.push_back(b_p);
    for(int i = 0; i < n; i++)
    {   
        cin >> temp;
        a_p += temp;
        a_arrs.push_back(temp);
        a_psum.push_back(a_p);
    }
    cin >> m;
    for(int j = 0; j < m; j++)
    {
        cin >> temp;
        b_p += temp;
        b_arrs.push_back(temp);
        b_psum.push_back(b_p);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            a_arr_sum.push_back(a_psum[i] - a_psum[j]);
        }
    }

    for(int k = 1; k <= m; k++)
    {
        for(int l = 0; l < k; l++)
        {
            b_arr_sum.push_back(b_psum[k] - b_psum[l]);
        }
    }
    sort(a_arr_sum.begin(), a_arr_sum.end());
    sort(b_arr_sum.begin(), b_arr_sum.end());
    long long res = 0;
    for(int i = 0; i < a_arr_sum.size(); i++)
    {
        long long lo_pos = lower_bound(b_arr_sum.begin(), b_arr_sum.end(), t - a_arr_sum[i]) - b_arr_sum.begin();
        long long up_pos = upper_bound(b_arr_sum.begin(), b_arr_sum.end(), t - a_arr_sum[i]) - b_arr_sum.begin();
        res += up_pos - lo_pos;
    }
    cout << res;
}