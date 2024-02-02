#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    double a, b;
    cin >> a >> b;
    double c = (a*sqrt(a*a+b*b)-a*a)/b;
    double d = sqrt(a*a+b*b) * c / sqrt(a*a + c*c);
    double e = sqrt(a*a+b*b) * c /(2*d);
    cout << round(e*100)/100 << ' ' << round(d*100)/100 ;
}