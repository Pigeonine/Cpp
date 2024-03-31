#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define DMAX 1000000000

using namespace std;

int arrs[5][5][100001];

vector<int> ords;

int main() {
    fastio;
    fill(&arrs[0][0][0], &arrs[4][4][100000], DMAX);
    int temp;
    while(true)
    {
        cin >> temp; 
        if(temp == 0) break;
        ords.push_back(temp);
    }
    int v_size = ords.size();
    for(int i = 0; i < v_size; i++)
    {
        if(i == 0)
        {
            arrs[0][ords[0]][0] = 2; arrs[ords[0]][0][0] = 2; continue;
        }
        
        switch (ords[i])
        {
        case 1:
            for(int j = 0; j <= 4; j++)
            {
                if(j == 1) continue;
                arrs[j][ords[i]][i] = 
                
            }
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        default:
            break;
        }



    }

}