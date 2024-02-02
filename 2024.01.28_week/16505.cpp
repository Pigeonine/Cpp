#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

char arrs[1025][1025]{};


int main() {
    fastio;
    fill(&arrs[0][0], &arrs[1024][1025], ' ');
    arrs[1][1] = '*';
    int n; cin >> n;
    int po = 1;
    for(int k = 1; k <= 10; k++)
    {
        for(int i = 1; i <= po; i++)
        {
            for(int j = 1; j <= po; j++)
            {
                arrs[i+po][j] = arrs[i][j];
                arrs[i][j+po] = arrs[i][j];
            }
        }
        po = po*2;
    }

    for(int i = 1; i <= pow(2,n); i++)
    {
        for(int j = 1; j <= pow(2,n)- i + 1; j++)
        {
            cout << arrs[i][j];
        }
        cout << "\n";
    }
}