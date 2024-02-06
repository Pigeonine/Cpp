#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<long long> n_arrs;

int main() {
    fastio;
    long long n, m, temp, counts; 
    while(true)
    {
        counts = 0;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for(int i = 0; i < n; i++) 
        {
            cin >> temp; n_arrs.push_back(temp);
        }
        for(int i = 0; i < m; i++)
        {
            cin >> temp;
            if(binary_search(n_arrs.begin(), n_arrs.end(), temp)) counts++; 
        }
        n_arrs.clear();
        cout << counts << "\n";
    }
}