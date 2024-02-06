#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    double x, y, next_x, next_y;
    cin >> a >> b;
    while(true)
    {
        next_x = (x+y)/2; next_y = 2*x*y/(x+y);
        if(abs(next_x - x) <= 0.000001 && abs(next_y - y) <= 0.000001)
            break;
        else {x = next_x; y = next_y;}
    }
    
}