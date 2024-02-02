#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

typedef unsigned long long ull;

using namespace std;



ull search(ull start, ull end, ull target)
{
    ull st = start, ed = end;
    //cout << st << ' ' << ed << endl;
    ull mid,result;
    
    while(st + 1 < ed){
        mid = (ull) ((ull)st + (ull)ed)/(ull)2;
        //cout << mid << endl;
        
        if((pow(mid,2))>= target){
            ed = mid;
            result = mid;
        }
        else if(mid * mid < target)
        {
            st = mid;
        }
    }

    return ed;
}

int main() {
    fastio;
    ull n; cin >> n; if(n == 0) {cout << 0; return 0;}
    ull st = pow(2,32) - 1;
    cout << search(0, st, n);
}