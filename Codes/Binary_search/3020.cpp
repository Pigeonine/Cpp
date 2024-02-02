#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> arrs_d;
int lo_arrs[500000]{}, up_arrs[500000]{};
long long arrs[500000]{};

int main() {
    fastio;
    int n,h,lo, up; cin >> n >> h;
    for(int i = 0; i< n/2; i++)
    {
        cin >> lo >> up;
        lo_arrs[lo-1]++; up_arrs[h-up]++;
    }
    long long lo_temp = 0, up_temp = 0;
    for(int i = h - 1; i >= 0; i--)
    {
        lo_temp += lo_arrs[i];
        //cout << lo_arrs[i] << endl;
        arrs[i] += lo_temp;
    }
    for(int i = 0; i <= h-1; i++)
    {
        up_temp += up_arrs[i];
        //cout << up_arrs[i] << endl;
        arrs[i] += up_temp;
    }



    for(int i = 0; i < h; i++)
        arrs_d.push_back(arrs[i]);
    sort(arrs_d.begin(), arrs_d.end());

    cout << arrs_d[0] << ' ' << upper_bound(arrs_d.begin(), arrs_d.end(), arrs_d[0]) - lower_bound(arrs_d.begin(), arrs_d.end(), arrs_d[0]);


}