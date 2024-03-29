#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

char arrs[3][3];
int i, j;
string s;
int main() {
    fastio;
    for(i = 0; i < 3; i++)
    {
        cin >> s;
        for(j = 0; j < 3; j++)
            arrs[i][j] = s[j];
    }
        
    bool res = false;
    for(i = 0; i < 3; i++)
    {
        if(arrs[0][i] != '.' && arrs[0][i] == arrs[1][i] && arrs[1][i] == arrs[2][i])
        {
            res = true; break;
        }
        if(arrs[i][0] != '.' && arrs[i][0] == arrs[i][1] && arrs[i][1] == arrs[i][2])
        {
            res = true; break;
        }
    }
    if(arrs[0][0] != '.' && arrs[0][0] == arrs[1][1] && arrs[1][1] == arrs[2][2])
        res = true;
    if(arrs[2][0] != '.' && arrs[2][0] == arrs[1][1] && arrs[1][1] == arrs[0][2])
        res = true;
    
    if(res) cout << "YES";
    else cout << "NO";
}