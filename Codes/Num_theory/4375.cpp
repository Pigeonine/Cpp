#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

long long pow3(long long base, int index, int mod = 10) {
    long long r = 1;
    while (index != 0) {
        if (index & 1) r = (r * base) % mod;
        base = (base * base) % mod;
        index >>= 1;
    }
    return r;
}

int main() {
    fastio;
    int n;
    int i = 1;
    while(cin >> n)
    {
        
        long long counts = 1, mods = 1 % n;
        while(true)
        {
            if(mods % n == 0)
            {
                cout << counts << "\n";
                break;
            }

            mods = (mods + pow3(10,counts,n)) % n; counts++;
        }
    }

}