#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    long long n, m, t, s;
    cin >> n >> m >> t >> s;
    long long n_times = (n-1)/8, m_times = (m-1)/8;
    n_times = n + n_times * s;
    m_times = m + m_times * (s + 2 * t) + t;
    if(n_times < m_times) cout << "Zip" << "\n" << n_times;
    else cout << "Dok" << "\n" << m_times;

}