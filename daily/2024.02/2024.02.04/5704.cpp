#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

bool arrs[26]{};

int main() {
    fastio; string s;
    while(true)
    {
        fill(arrs, arrs+26, false);
        getline(cin,s);
        if(s == "*") break;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z') 
            {
                arrs[s[i]-'a'] = true;
            }
        }
        
        bool checks = true;

        for(int i = 0; i < 26; i++)
        {
            //cout << arrs[i] << endl;
            if(!arrs[i]) 
            {
                checks = false; break;
            }
        }
        if(checks) cout << "Y" << "\n";
        else cout << "N" << "\n";

    }
}