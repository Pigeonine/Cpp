#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int n; cin >> n;
    long long sums = 0;
    long long temp = n, dig = 1, dig_n = 1;
    while(temp >= 10)
    {
        temp /= 10; sums = (sums + (9 * dig_n * dig) % 1234567) % 1234567; dig *= 10; dig_n++;
        //cout << sums << endl;
    }
    //cout << temp << ' ' << dig << ' ' << dig_n << "\n";
    sums = (sums + ((n - dig + 1) * dig_n)% 1234567)% 1234567;
    cout << sums;
    
}