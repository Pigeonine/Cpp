#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int arrs[12][12];

int maxd = -40001;
int n, m, k;
bool visited[12][12]{};
void dfs(int r, int c, int num, int sums)
{
    if(num == k) {
        maxd = max(maxd,sums); return;
    }

    for(int i = c + 2; i <= m; i++)
    {
        if(!visited[r-1][i] && !visited[r][i-1] && !visited[r][i+1] && !visited[r+1][i])
        {
            visited[r][i] = true;
            dfs(r,i, num + 1, sums + arrs[r][i]);
            visited[r][i] = false;
        }
    }

    for(int i = r + 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(!visited[i-1][j] && !visited[i][j-1] && !visited[i][j+1] && !visited[i+1][j])
        {
            visited[i][j] = true;
            dfs(i,j, num + 1, sums + arrs[i][j]);
            visited[i][j] = false;
        }
        }
    }
}


int main() {
    fastio;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> arrs[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            visited[i][j] = true;
            dfs(i,j,1,arrs[i][j]);
            visited[i][j] = false;
        }
    }
    cout << maxd;

}