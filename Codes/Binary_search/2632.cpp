#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;


vector<int> pizza_a_psum;
vector<int> pizza_b_psum;

vector<int> pizza_a_comb;
vector<int> pizza_b_comb;

int main() {
    fastio;
    int target, m,n; cin >> target >> m >> n;
    vector<int> pizza_a(m); vector<int> pizza_b(n);
    int p_asum =0, p_bsum = 0;
    for(auto &i : pizza_a) 
    {
        cin >> i;
        p_asum += i; pizza_a_psum.push_back(p_asum);
    }
    for(auto &i : pizza_b) 
    {
        cin >> i;
        p_bsum += i; pizza_b_psum.push_back(p_bsum);
    }

    pizza_a_comb.push_back(0);pizza_b_comb.push_back(0);
    pizza_a_comb.push_back(pizza_a_psum[m-1]);pizza_b_comb.push_back(pizza_b_psum[n-1]);
    for(int i = 1; i < m; i++)
    {
        for(int j = i; j < m; j++)
        {
            pizza_a_comb.push_back(pizza_a_psum[j] - pizza_a_psum[i-1]);
            pizza_a_comb.push_back(pizza_a_psum[m-1] - pizza_a_psum[j] + pizza_a_psum[i-1]);
        }
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            pizza_b_comb.push_back(pizza_b_psum[j] - pizza_b_psum[i-1]);
            pizza_b_comb.push_back(pizza_b_psum[n-1] - pizza_b_psum[j] + pizza_b_psum[i-1]);
                
        }
    }
    int counts = 0;
    sort(pizza_b_comb.begin(), pizza_b_comb.end());
    int asize = pizza_a_comb.size();
    for(int i = 0; i < asize; i++)
    {

        counts += upper_bound(pizza_b_comb.begin(), pizza_b_comb.end(), target - pizza_a_comb[i])
        - lower_bound(pizza_b_comb.begin(), pizza_b_comb.end(), target - pizza_a_comb[i]);
    }
    cout << counts;
}