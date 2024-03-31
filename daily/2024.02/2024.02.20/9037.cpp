#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;
int arrs[10];
int temp[10];

int main() {
    fastio;

    int t; cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n; cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> arrs[i];
        }
        int cnts = 0;
        while(true)
        {
            bool fin = true;
            for(int i = 0; i < n; i++)
            {
                if(arrs[i] % 2 != 0) arrs[i]++;
            }

            for(int i = 1; i < n; i++)
            {
                if(arrs[i] != arrs[i-1])
                {
                    fin = false; break;
                }
            }

            if(fin) {
                cout << cnts << "\n";
                break;
            }

            for(int i = 0; i < n; i++)
            {
                temp[i] = arrs[i]/2;
                arrs[i] /= 2;
            }
            for(int i = 1; i < n; i++)
            {
                arrs[i] += temp[i-1];
            }
            arrs[0] += temp[n-1];
            cnts++;
        }


    }
}