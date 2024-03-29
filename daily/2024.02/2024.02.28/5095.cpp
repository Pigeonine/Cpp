#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int res[100][100];
int res_t[100][100];
int temp[100][100];
int temp_t[100][100];
int n, m, p; 

void mpow()
{
    fill(&res[0][0], &res[99][100], 0);
    for(int i = 0; i < n; i++) res[i][i] = 1;
    int numb = 1;
    while(numb <= p)
    {
        fill(&temp_t[0][0], &temp_t[99][100], 0);
        fill(&res_t[0][0], &res_t[99][100], 0);
        if(numb & p)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    for(int k = 0; k < n; k++)
                    {
                        res_t[i][j] = ((res[i][k] * temp[k][j]) % m + res_t[i][j]) % m;
                    }
                }
            }
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    res[i][j] = res_t[i][j];
                }
            }
        }

        numb *= 2;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    temp_t[i][j] = ((temp[i][k] * temp[k][j]) % m + temp_t[i][j]) % m;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                temp[i][j] = temp_t[i][j];
            }
        }

    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << "\n";
    }
    cout << "\n";
}


int main() {
    fastio;
    
    while(cin >> n >> m >> p)
    {
        if(n == 0 && m == 0 && p == 0) break;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> temp[i][j]; 
            }
        }
        mpow();
    }
}