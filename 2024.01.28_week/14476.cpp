#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> arrs;

vector<int> pre_arrs;
vector<int> post_arrs;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
    fastio;
    int n,pre_gcd, post_gcd, temp; cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp; arrs.push_back(temp);
    }
    pre_arrs.push_back(arrs[0]);
    pre_gcd = arrs[0];
    for(int i = 1; i < n; i++)
    {
        pre_gcd = gcd(pre_gcd, arrs[i]);
        pre_arrs.push_back(pre_gcd);
    }
    post_arrs.push_back(arrs[n-1]);
    post_gcd = arrs[n-1];
    for(int i = n-2; i >= 0; i--)
    {
        post_gcd = gcd(post_gcd, arrs[i]);
        post_arrs.push_back(post_gcd);
    }
    reverse(post_arrs.begin(), post_arrs.end());

    int max_prime = -1, target_num; 
    if(arrs[0]%post_arrs[1] != 0){
        max_prime = post_arrs[1]; target_num = arrs[0];
    }

    for(int i = 1; i < n-1; i++)
    {
        int pr = gcd(pre_arrs[i-1], post_arrs[i+1]);
        if(arrs[i]%pr != 0)
        {
            if(pr > max_prime)
            {
                max_prime = pr; target_num = arrs[i];
            }
        }
    }

    if(arrs[n-1]%pre_arrs[n-2] != 0){
        
        if(pre_arrs[n-2] > max_prime)
        {
            max_prime = pre_arrs[n-2]; target_num = arrs[n-1];
        }
    }

    if(max_prime == -1) cout << max_prime;
    else cout << max_prime << ' ' << target_num;
}