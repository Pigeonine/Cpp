#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int arrs[10] = {4,2,5,5,4,5,6,3,7,6};
int main() {
    fastio;
    int n; cin >> n;
    if(n == 2) cout << 1;
    //else if(n == 3) cout << 7;
    //else if(n == 4) cout << 4;
    //else if(n == 5) cout << 8;
    else{
        if(n%3 == 0)
            cout << (n/3) * 7;
        else if(n%3 == 1)
            cout << (n/3-1) * 7 + 4;
        else if(n%3 == 2)
            cout << (n/3) * 7 + 1;
    }
}