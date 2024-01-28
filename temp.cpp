#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int mat[2][2];
int res[2]{};

void init()
{
    res[0] = 1; res[1] = 0;
    mat[0][0] = 1; mat[0][1] = 1; mat[1][0] = 1; mat[0][0] = 0;
}

void mrmult(int mod)
{
    int temp[2];
    for(int i = 0;  i < 2; i++)
    {
        int sum = 0;
        for(int k = 0; k < 2; k++) 
        {
            sum += mat[i][k] * res[k];
        }
        temp[i] = sum % mod;
    }
    for(int i = 0; i < 2; i++)
    {
            res[i] = temp[i];
    }
}

void mmmult(int mod)
{
    int temp[2][2];
    for(int i = 0;  i < 2; i++)
    {
        for(int k = 0; k < 2; k++) 
        {
            int sum = 0;
            for(int m = 0; m < 2; m++)
            {
                sum += mat[i][m] * mat[m][k];
            }
            temp[i][k] = sum % mod;
        }
    }
    for(int i = 0; i < 2; i++)
    {
        for(int k = 0; k < 2; k++) 
        {
            mat[i][k] = temp[i][k];
        }
    }
}

void pow_mat(long long B, int mod) {
    while (B != 0) {
        if (B & 1) mrmult(mod);
        mmmult(mod);
        B >>= 1;
    }
    return;
}

int main() {
    fastio;
    long long B;
    int mod_t = 1000000;
    cin >> B;
    init();
    
    if(B == 0) cout << 0;
    else{
    pow_mat(B-1, mod_t);
    
    cout << res[0];
    }
        
}