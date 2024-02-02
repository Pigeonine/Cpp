#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int arrs[1000]{};

int main() {
    fastio;
    string s;
    cin >> s;
    int p_sum = 0;
    for(int i = 0; i < s.length(); i ++)
    {
        p_sum += s[i]; arrs[i] = p_sum;
    }
    int start = s.length()/2;
    for(int i = start; i > 0; i--)
    {
        int j = 0;
        while(j + 2 * i <= s.length())
        {
            int lsum = 0, rsum = 0;
            for(int k = j; k < j + i; k++)
            {
                lsum += s[k] - '0';
            }
            for(int k = j + i; k < j + 2 * i; k++)
            {
                rsum += s[k] - '0';
            }
            if(lsum == rsum) 
            {
                cout << 2*i;
                return 0;
            }
            j++;
        }
    }
    cout << 0;

}