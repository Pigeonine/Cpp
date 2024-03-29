#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int t; cin >> t;
    string a, b; double xa, xb, ya, yb, za, zb;
    for(int i = 0; i < t; i++)
    {   cin.ignore();
        getline(cin, a);
        cin >> xa >> ya >> za;
        cin.ignore();
        getline(cin, b);
        cin >> xb >> yb >> zb;
        //cout << a << ' ' << xa << ' ' << ya <<' ' << za <<' ' << b <<' ' << xb <<' ' << yb <<' ' << zb << endl;
        double res = sqrt(pow(xa-xb, 2) + pow(ya - yb, 2) + pow(za - zb, 2));
        res = round(res * 100) / 100;
        cout.precision(2); cout << fixed;
        cout << a << " to " << b << ": " << res << "\n";
    }
}