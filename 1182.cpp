#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<long long> arrs;


int main() {
    fastio;
    long long n, s, temp, count = 0; cin >> n >> s;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;  arrs.push_back(temp);
    }
    int order_bit = 1;
    while(order_bit < (1 << n))
    {   
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(order_bit & (1<<i)) sum += arrs[i];
        }
        if(sum == s) count++;

        order_bit++;
    }
    cout << count;
}