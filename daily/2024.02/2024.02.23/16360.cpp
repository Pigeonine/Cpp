#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int n; cin >> n; string s;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        int s_size = s.size();
        switch (s[s_size-1])
        {
        case 'a':
            s += "s";
            break;
        case 'i':
            s += "os";
            break;
        case 'y'://
            s[s_size-1] = 'i'; s += "os";
            break;
        case 'l':
            s += "es";
            break;
        case 'n':
            s[s_size-1] = 'a'; s += "nes";
            break;
        case 'e': // ne
            if(s_size < 2 )
            {
                s+="us"; break;
            }
            if(s[s_size-2] == 'n') {
                s[s_size-2] = 'a'; s[s_size-1] = 'n'; s += "es";
            }
            else s += "us";
            break; 
        case 'o'://
            s += "s";
            break; 
        case 'r'://
            s += "es";
            break;
        case 't':
            s += "as";
            break;
        case 'u':
            s += "s";
            break;
        case 'v':
            s += "es";
            break;  
        case 'w':
            s += "as";
            break;             
        default:
            s += "us";//
            break;
        }
        cout << s << "\n";
    }

}