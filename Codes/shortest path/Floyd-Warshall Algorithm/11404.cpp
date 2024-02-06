#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define INF 1000000000


using namespace std;

int cities[101][101];
int dist[101][101];

int main() {
    fastio;
    int n, m, a, b, c;
    cin >> n >> m;
    fill(&cities[1][1], &cities[100][101], INF);
    for(int i = 1; i <= n; i++) cities[i][i] = 0;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        cities[a][b] = min(c, cities[a][b]);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dist[i][j] = cities[i][j];
        }
    }
    
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++ )
        {
            for(int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dist[i][j] == INF) cout << 0 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << "\n";
    }
    
}