#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<long long> arrs;

vector<long long> arrs_sum;

int main() {
    fastio;
    int n, temp; cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp; arrs.push_back(temp);
    }
    sort(arrs.begin(), arrs.end());
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arrs_sum.push_back(arrs[i]+arrs[j]);
        }
    }
    
    sort(arrs_sum.begin(), arrs_sum.end());
    bool a = false;
    for(int i = n-1; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(binary_search(arrs_sum.begin(), arrs_sum.end(), arrs[i] - arrs[j]))
            {
                cout << arrs[i];
                a = true;
                break;
            }
        }
        if(a) break;
    }
}