#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int arrs[5]{};

int main() {
    fastio;
    int n;
    while(cin >> n){
        if(n == 0) break;
        fill(arrs, arrs+5,0);
        string s;
        for(int i = 0; i < n; i++)
        {
            cin >> s;
            if(s[0] >= 'A' && s[0] <= 'Z')
            {
                if(s[0] == 'M' || s[0] == 'L') arrs[0]++;
                else if(s[0] == 'S') arrs[3]++;
                else arrs[4]++;
            }
            else{
                int a = stoi(s);
                if(a >= 12) arrs[1]++;
                else if(a < 12) arrs[2]++;
            }
        }

        for(int i = 0; i < 5; i++)
            cout << arrs[i] << ' ';
        cout << "\n";
    }
    
}