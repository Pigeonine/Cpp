#include <iostream>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int arrs[10]{};

int main()
{
    fastio;
    string s; cin >> s; int sums = 0;
    for(int i = 0; i < s.length(); i++) {
        arrs[s[i]-'0']++; sums += s[i] - '0';
    }
    if(arrs[0] == 0 || sums % 3 != 0)
    {
        cout << -1; return 0;
    }

    for(int i = 9; i >= 0; i--)
    {
        while(arrs[i] != 0)
        {
            cout << i; arrs[i]--;
        }
    }
}