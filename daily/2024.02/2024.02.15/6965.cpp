#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int n; cin >> n; cin.ignore(); string s;
    for(int i = 0; i < n; i++)
    {
        getline(cin, s);
        istringstream ss(s);
        string temp;
        while(getline(ss, temp, ' '))
        {
            if(temp.length() == 4) cout << "****" << ' ';
            else cout << temp << ' ';
        }
        cout << "\n" << "\n";
    } 
}