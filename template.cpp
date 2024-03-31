#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int t;
string s;
int main() {
    fastio;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cin >> s;
        switch (s[s.size()-1])
        {
        case 'y':
            cout << "Case #" << i << ": " << s << " is ruled by nobody.";
            break;
        case 'a':
            cout << "Case #" << i << ": " << s << " is ruled by a queen.";
            break;
        case 'o':
            cout << "Case #" << i << ": " << s << " is ruled by a queen.";
            break;
        case 'u':
            cout << "Case #" << i << ": " << s << " is ruled by a queen.";
            break;
        case 'e':
            cout << "Case #" << i << ": " << s << " is ruled by a queen.";
            break;
        case 'i':
            cout << "Case #" << i << ": " << s << " is ruled by a queen.";
            break;    
        default:
            cout << "Case #" << i << ": " << s << " is ruled by a king.";
            break;
        }
        cout << "\n";
    }

} 
