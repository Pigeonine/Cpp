#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int arrs[20][2];

vector<vector<int>> comb;

int ans[20]{};

int n, p, e;

void dfs(int index, vector<int> cur_comb)
{
    if(cur_comb.size() == p)
        comb.push_back(cur_comb);
    

    if(index >= n-1) return;
    for(int i = index + 1; i < n; i++)
    {
        vector<int> temp(cur_comb); temp.push_back(i);
        dfs(i,temp);
    }
}


int main() {
    fastio;
    cin >> n >> p >> e;
    for(int i = 0; i < n; i++)
        cin >> arrs[i][0] >> arrs[i][1];
    
    
    for(int i = 0; i < n; i++)
    {
        vector<int> temp; temp.push_back(i);
        dfs(i, temp);
    }

    for(int i = 0; i < comb.size(); i++)
    {
        int min_sums = 0, max_sums= 0;
        for(int j = 0; j < comb[i].size(); j++)
        {
            min_sums += arrs[comb[i][j]][0];
            max_sums += arrs[comb[i][j]][1];
        }
        if(max_sums >= e && min_sums <= e)
        {
            int dif = e - min_sums;
            for(int j = 0; j < comb[i].size(); j++)
            {
                ans[comb[i][j]] = arrs[comb[i][j]][0];
            }
            for(int j = 0; j < comb[i].size(); j++)
            {
                if(dif > arrs[comb[i][j]][1] - arrs[comb[i][j]][0])
                {
                    ans[comb[i][j]] = arrs[comb[i][j]][1];
                    dif -= arrs[comb[i][j]][1] - arrs[comb[i][j]][0];
                }
                else 
                {
                    ans[comb[i][j]] += dif;
                    for(int k = 0; k < n; k++) cout << ans[k] << ' ';
                    return 0;
                }
            }
        }
    }
    cout << -1;

}