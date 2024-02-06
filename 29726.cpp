#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> arrs;

vector<int> pre_min_arrs;
vector<int> post_max_arrs;

int main() {
    fastio;
    int n, m, temp; cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> temp; arrs.push_back(temp);
    }
    pre_min_arrs.push_back(arrs[0]);
    int pre_min = arrs[0];
    for(int i = 1; i <= m; i++)
    {   
        pre_min = min(pre_min, arrs[i]);
        pre_min_arrs.push_back(pre_min);
    }
    int post_max = arrs[n-1];
    post_max_arrs.push_back(post_max);
    for(int i = n-2; i >= n-2-m+1; i--)
    {
        post_max = max(post_max, arrs[i]);
        post_max_arrs.push_back(post_max);
    }
    
    reverse(post_max_arrs.begin(), post_max_arrs.end());

    for(int i = 0; i <= m; i++)
        cout << pre_min_arrs[i] << ' ';
    cout << "\n";
    for(int i = 0; i <= m; i++)
        cout << post_max_arrs[i] << ' ';
    cout << "\n";
    int max_res = -100001;
    for(int i = 0; i <= m; i++)
        max_res = max(max_res, post_max_arrs[i]-pre_min_arrs[i]);
    cout << max_res;
}