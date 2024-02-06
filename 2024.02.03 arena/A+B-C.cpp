#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    string a,b,c;
    cin >> a >> b >> c;
    cout << stoi(a) + stoi(b) - stoi(c) << "\n";
    string d = a + b;
    cout << stoi(d) - stoi(c) << "\n";
}