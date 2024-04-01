#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int n, arrs[1001],maxd, ind;
bool checked[1001];


int main() {
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arrs[i];
    for(int i = 1; i <= n; i++)
    {
        fill(checked+1,checked+n+1, false);
        checked[i] = true;
        int s = 1, next = arrs[i];
        while(true)
        {
            if(checked[next]) break;
            
            s++; checked[next] = true; next = arrs[next];
        }
        if(maxd < s) {maxd = s; ind = i;}
    }
    cout << ind;
}