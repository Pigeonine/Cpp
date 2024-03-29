#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int mw, mb, tw, tb, pw, pb, mw_min, mb_min;

int main() {
    fastio;
    cin >> mw >> mb >> tw >> tb >> pw >> pb;
    mw_min = min(mw,min(tb,pw)); mb_min = min(mb,min(tw, pb));
    if(mw_min == mb_min) cout << 2 * mw_min;
    else cout << 2 * min(mw_min, mb_min) + 1;
    
}