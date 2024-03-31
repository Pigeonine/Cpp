#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int t; cin >> t; string s, p;
    for(int i = 0; i < t; i++)
    {
        cin >> s >> p;
        int times = 0;
        while(s.find(p) != string::npos)
        {
            s.erase(s.find(p), p.length()); times++;
        }
        times += s.length();
        cout << times << "\n";
    }


}