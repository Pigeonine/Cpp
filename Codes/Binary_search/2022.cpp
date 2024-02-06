#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;
double x, y, c;

double search(double start, double end)
{
    double st = start, ed = end;
    double mid;
    while(abs(ed - st) >= 1e-6){
        mid = (st + ed)/2;
        
        double h1 = sqrt(max(x,y) * max(x,y) - mid * mid);
        double h2 = sqrt(min(x,y) * min(x,y) - mid * mid);
        double h = h1*h2/(h1+h2);
        if(h > c){
            st = mid;
        }
        else if(h <= c)
        {
            ed = mid;
        }
    }
    return mid;
}

int main() {
    fastio;
    cin >> x >> y >> c;

    cout << search(0, min(x,y));
}