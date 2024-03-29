#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define MINSUM -2000000000


using namespace std;


int arrs[250001];


int main() {
    fastio;
    int n;
    while(cin >> n) // sums would be zero if all datas are negative. can choose one data by caculating min data
    {
        if(n == 0) break;
        for(int i = 1; i <= n; i++) cin >> arrs[i];
        long long sums = 0, rsums = 0;
        for(int i = 1; i <= n; i++) 
        {
            rsums += arrs[i];
            if(rsums > sums) sums = rsums;
            else if(rsums < 0) rsums = 0;
        }
        cout << sums << "\n";
    }
        
    
}