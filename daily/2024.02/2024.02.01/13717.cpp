#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<string> po_name;
vector<int> candy_count;
vector<int> candy_req;

int main() {
    fastio;
    int n,k,m, total_evo = 0, evo_max = 0; cin >> n;
    string s, max_po;
    for(int i = 0; i < n; i++)
    {   
        cin >> s >> k >> m;
        po_name.push_back(s); candy_count.push_back(m); candy_req.push_back(k);
    }
    for(int i = 0; i < n; i++)
    {
        int evo_count;
        if(candy_count[i]%(candy_req[i]-2) >= 2)
        {
            evo_count = candy_count[i]/(candy_req[i]-2);
            total_evo+=evo_count;
            if(evo_max < evo_count) 
            {
                evo_max = evo_count; max_po = po_name[i];
            }
        }
        else{
            evo_count = max(candy_count[i]/(candy_req[i]-2)-1, 0);
            total_evo+=evo_count;
            if(evo_max < evo_count) 
            {
                evo_max = evo_count; max_po = po_name[i];
            }
        }
    }
    cout << total_evo << ' ' << "\n" << max_po;
}