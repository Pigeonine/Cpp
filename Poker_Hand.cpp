#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int arrs[14]{};


int main() {
    fastio;
    string s;
    for(int i = 0; i < 5; i++)
    {
        cin >> s;
        if(s[0] == 'A') arrs[1]++;
        else if(s[0] == 'T') arrs[10]++;
        else if(s[0] == 'J') arrs[11]++;
        else if(s[0] == 'Q') arrs[12]++;
        else if(s[0] == 'K') arrs[13]++;
        else arrs[s[0]-'0']++;
    }

    int maxd = 0;
    for(int i = 1; i <= 13; i++)
        maxd = max(maxd, arrs[i]);
    cout << maxd;
}