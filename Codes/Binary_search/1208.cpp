#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<long long> arrs_1, arrs_2, arrs_1_psum, arrs_2_psum;


int main() {
    fastio;
    long long n, s, temp, count = 0; cin >> n >> s;
    for(int i = 0; i < n/2; i++)
    {
        cin >> temp;  arrs_1.push_back(temp);
    }
    for(int i = n/2; i < n; i++)
    {
        cin >> temp;  arrs_2.push_back(temp);
    }
    int order_bit = 1;
    while(order_bit < (1 << arrs_1.size()))
    {   
        int sum = 0;
        for(int i = 0; i < arrs_1.size(); i++)
        {
            if(order_bit & (1<<i)) sum += arrs_1[i];
        }
        arrs_1_psum.push_back(sum);
        order_bit++;
    }
    order_bit = 1;
    while(order_bit < (1 << arrs_2.size()))
    {   
        int sum = 0;
        for(int i = 0; i < arrs_2.size(); i++)
        {
            if(order_bit & (1<<i)) sum += arrs_2[i];
        }
        arrs_2_psum.push_back(sum);
        order_bit++;
    }
    sort(arrs_2_psum.begin(), arrs_2_psum.end());
    for(int i = 0; i < arrs_1_psum.size(); i++)
    {
        count+= upper_bound(arrs_2_psum.begin(), arrs_2_psum.end(), s-arrs_1_psum[i]) - lower_bound(arrs_2_psum.begin(), arrs_2_psum.end(), s-arrs_1_psum[i]);
    }
    for(int i = 0; i < arrs_2_psum.size(); i++)
    {
        if(arrs_2_psum[i] == s) count++;
    }
    for(int i = 0; i < arrs_1_psum.size(); i++)
    {
        if(arrs_1_psum[i] == s) count++;
    }
    cout << count;
}