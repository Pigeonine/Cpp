#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int n, m; cin >> n >> m;
    string s, s_t; cin >> s;
    for(int i = 1; i < n; i++)
    {   
        cin >> s_t;
        bool t = false;
        for(int j = 1; j < m; j++)
        {
            if(s.substr(0,j) == s_t.substr(m-j,j))
            {
                t = true; break;
            }
            if(s.substr(m-j,j) == s_t.substr(0,j))
            {
                t = true; break;
            }
        }
        if(s == s_t) t = true; 

        
        if(!t) {
            cout << 0; return 0;
        }
        s = s_t;
    }
    cout << 1;
}