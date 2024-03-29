#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    while(true)
    {
        string s;
        getline(cin, s);
        if(s == "*") break;
        istringstream ss(s);
        string word; char c; int cnts = 0;
        bool isT = true;
        while(getline(ss, word, ' '))
        {
            if(cnts == 0) {c = tolower(word[0]);cnts++;}
            else {
                if(c != tolower(word[0])) 
                {
                    isT = false; break;
                }
            }
            
        }
        if(isT) cout << 'Y' << "\n"; 
        else cout << 'N' << "\n";
    }
}