#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;


void permu(string str, int l, int pos, string p_str)
{
    if(l == 1) {cout << p_str << str << "\n"; return;}
    p_str.push_back(str[pos]);
    str.erase(str.begin()+pos);
    for(int i = 0; i < l-1; i++)
    {
        permu(str, l-1, i,p_str);
    }
}

int main() {
    fastio;
    int t; string s; cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case # " << i << ':' << "\n";
        cin >> s;
        int ssize = s.size();
        for(int i = 0; i < ssize; i++)
        {
            permu(s, ssize, i,"");
        }
    }

    
}