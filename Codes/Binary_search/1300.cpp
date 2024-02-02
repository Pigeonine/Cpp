#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int n, k;

int search(int start, int end, int target)
{
    int st = start, ed = end;
    int mid, result;
    int cou;
    while(st <= ed){
        cou = 0;
        mid = (st + ed)/2;
        for(int i = 1; i <= min(n, mid); i++)
        {
            cou += min(n, mid/i);
        }
        if(cou >= target){
            ed = mid-1;
            result = mid;
        }
        else if(cou < target)
        {
            st = mid + 1;
        }
        //cout << mid << ' ' << cou << ' ' << result << endl;
    }
    return result;
}


int main() {
    fastio;
    cin >> n >> k;
    cout << search(1, k, k);
}