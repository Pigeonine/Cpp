#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int arrs[1024];

int main() {
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arrs[i];
    for(int i = 1; i < n; i++)
    {
        if(arrs[i] - arrs[i-1] < 0) 
        {
            cout << "no"; return 0;
        }
    }
    
    cout << "yes";
    
}