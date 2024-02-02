#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;
long long x, y;


int search(int start, int end, long long target)
{
    long long st = start, ed = end;
    long long mid,result = -1;
    long long cou;
    while(st <= ed){
        cou = 0;
        mid = (st + ed)/2;
        int z_f = (y+mid) * 100 / (x+mid);
        if(z_f > target){
            ed = mid-1;
            result = mid;
        }
        else
        {
            st = mid + 1;
        }
    }
    return result;
}

int main() {
    fastio;

    cin >> x >> y;
    long long z = (y * 100) / x;
    cout << search(1,2000000000,z);
}