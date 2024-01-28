#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define INF 25000001


using namespace std;

vector<tuple<int,int,int>> ways;

int dist[501];

bool cycle_d;

void bellman_ford(int start, int n, int m, int w)
{
    
    dist[start] = 0;
    int last_d = n-1;
    for(int a = 0; a <n; a++){
        for(int j = 0; j < m+w; j++)
        {
            int cost = get<2>(ways[j]);
            int s_p = get<0>(ways[j]);
            int e_p = get<1>(ways[j]);
            if(cost > 0)
            {
                if(dist[s_p] != INF && dist[e_p] != INF)
                {
                    if(dist[s_p] > dist[e_p] +cost){
                        dist[s_p] = dist[e_p]+cost; if(a == last_d) cycle_d = true;
                    }
                    if (dist[s_p]+cost < dist[e_p]){
                        dist[e_p] = dist[s_p]+cost; if(a == last_d) cycle_d = true;
                    }
                }
                else if(dist[s_p] != INF)
                {
                    dist[e_p] = dist[s_p]+cost; if(a == last_d) cycle_d = true;
                }
                else if(dist[e_p] != INF)
                {
                    dist[s_p] = dist[e_p]+cost; if(a == last_d) cycle_d = true;
                }
            }
            else
            {
                if(dist[s_p] != INF && dist[e_p] > dist[s_p] + cost)
                {
                    dist[e_p] = dist[s_p] + cost;
                    if(a == last_d) cycle_d = true;
                }
            }
            
        }
    }
}



int main() {
    fastio;
    int tc, n, m, w, s, e, t;
    
    cin >> tc;
    for(int i = 0; i < tc; i++)
    {
        cycle_d = false;
        cin >> n >> m >> w;
        fill(dist+1, dist+1+n, INF);
        for(int j = 0; j < m; j++)
        {
            cin >> s >> e >> t;
            ways.push_back({s,e,t});
        }
        
        for(int j = 0; j < w; j++)
        {
            cin >> s >> e >> t;
            ways.push_back({s,e,-t});
        }
        
        bellman_ford(1,n,m,w);
        
        for(int i = 1; i <= n; i++)
        {
            if(dist[i] == INF) bellman_ford(i,n,m,w);
        }
        
        
        //for(int i = 1; i <= n; i++) cout << dist[i] << ' ';
        //cout << "\n";
        
        
        //for(int i = 0; i < ways.size(); i++)
        //{
        //    cout << get<0>(ways[i]) << ' ' << get<1>(ways[i]) << ' ' << get<2>(ways[i]) << "\n";
        //}
        
        ways.clear();
        
        
        
        if(cycle_d) cout << "YES"<< "\n";
        else cout << "NO" << "\n";
    }
}