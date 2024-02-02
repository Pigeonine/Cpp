#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> a_arrs, b_arrs, a_psum, b_psum;


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
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            int as = a_psum[i] - a_psum[j];
            for(int k = 1; k <= m; k++)
            {
                for(int l = 0; l < k; l++)
                {
                    if(a_psum[i] - a_psum[j] + b_psum[k] - b_psum[l] == t) res++;
                }
            }
        }
    }

    cout << res;
}