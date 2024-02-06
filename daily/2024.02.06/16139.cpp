#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int arrs[200000][26]{};

int main() {
    fastio;
    string s; int n, fir, sec; cin >> s >> n;
    char a; 
    int len = s.length();
    arrs[0][s[0]-'a']++;
    for(int i = 1; i < len; i++)
    {
        copy_n(arrs[i-1], 26, arrs[i]);
        arrs[i][s[i]-'a']++;
    }
    for(int i =0; i < n; i++)
    {
        cin >> a >> fir >> sec;
        if(fir == 0) cout << arrs[sec][a-'a'] << "\n";
        else cout << arrs[sec][a-'a'] - arrs[fir-1][a-'a'] << "\n";
    }
}