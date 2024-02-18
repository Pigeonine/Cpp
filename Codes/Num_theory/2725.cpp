#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

bool arrs[1001][1001]{};
int res[1001]{};

int gcd(int a, int b)
{
    while(a % b != 0)
    {
        int r = a % b;
        a = b; b = r;
    }
    return b;
}

void init()
{
    res[1] = 3; 
    for(int i = 2; i <= 1000; i++)
    {
        
        arrs[0][i] = true; arrs[i][0] = true;
        arrs[i][i] = true;
    }
    for(int i = 2; i <= 1000; i++)
    {
        int sums = 0;
        for(int j = 1; j < i; j++)
        {
            if(!arrs[i][j])
            {
                sums +=2;
                int x = 2*i, y = 2*j;
                while(x <= 1000)
                {
                    arrs[x][y] = true; arrs[y][x] = true;
                    x += i; y += j;
                }
            }
        }
            
        res[i] = res[i-1] + sums;
    }
}

int main() {
    fastio;
    int t, temp; cin >> t;
    init();
    for(int i = 0; i < t; i++)
    {
        cin >> temp; cout << res[temp] << "\n";
    }
}