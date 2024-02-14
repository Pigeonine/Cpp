#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int arrs[11];

int real_arrs[11];
int real_arrs_index[11];
int main() {
    fastio;
    int n; cin >> n; 
    fill(real_arrs, real_arrs + n + 1, 11);
    for(int i = 1; i <= n; i++) cin >> arrs[i];

    for(int i = 1; i <= n; i++)
    {
        int temp = arrs[i]+1;
        for(int j = 1; j <= temp; j++)
        {
            if(real_arrs[j] <= i) ++temp;
            //cout << temp << ' ' << j << ' ' << i << endl;
        }
        //cout << "\n";
        real_arrs[temp] = i; real_arrs_index[i] = temp;
        //cout << i << ' ' << temp << endl;
    }
    for(int i = 1; i <= n; i++) cout << real_arrs[i] << ' ';
}