#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int arrs[2000001];

int inc_arrs[2000001]{};

int main() {
    fastio;
    int n, cont_num = 1; cin >> n;
    long long counts = 0;

    for(int i = 0; i < n; i++) cin >> arrs[i];

    counts++;

    for(int i = 1; i < n; i++)
    {
        if(arrs[i] > arrs[i-1]) cont_num++;
        else cont_num = 1;
        counts += cont_num;
    }
    cout << counts;
}