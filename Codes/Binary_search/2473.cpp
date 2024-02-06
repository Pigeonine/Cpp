#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<long long> arrs;
vector<long long> dd;
int main() {
    fastio;
    long long n, temp; cin >> n;
    long long f, s, t;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        arrs.push_back(temp);
    }
    sort(arrs.begin(), arrs.end());
    long long min_sum = 3000000001;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            long long t_sum = arrs[i] + arrs[j];
            long long up_pos = lower_bound(arrs.begin(), arrs.end(), -t_sum) - arrs.begin();
            long long lo_pos = up_pos - 1;
            while(up_pos == i || up_pos == j) {up_pos = up_pos + 1;}
            while(lo_pos == i || lo_pos == j) {lo_pos = lo_pos - 1;}
            if(up_pos < arrs.size())
            {
                if(min_sum > abs((long long) (t_sum + arrs[up_pos]))) 
                {
                    //cout << i << ' ' << j << ' ' << up_pos << endl;
                    f = arrs[i]; s = arrs[j]; t = arrs[up_pos];
                    min_sum = abs((long long)(f+s+t));
                }
            }
            if(lo_pos >= 0)
            {
                if(min_sum > abs((long long) (t_sum + arrs[lo_pos]))) 
                {
                    //cout << i << ' ' << j << ' ' << lo_pos << endl;
                    f = arrs[i]; s = arrs[j]; t = arrs[lo_pos];
                    min_sum = abs((long long)(f+s+t));
                }
            }
        }
    }
    dd.push_back(f);dd.push_back(s);dd.push_back(t);
    sort(dd.begin(), dd.end());
    cout << dd[0] << ' ' << dd[1] << ' ' << dd[2];
}