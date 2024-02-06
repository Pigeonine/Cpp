//https://karen0117.tistory.com/106

#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;
bool tomatos[1000][1000]{};

queue<pair<int,int>> q;

int main() {
    fastio;
    int m, n,temp;
    cin >> m >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> temp;
            if(temp == 1) q.push(make_pair(i,j));
            if(temp == 1 || temp == -1) tomatos[i][j] = true;
        } 
    }
    int count = -1;
    while(!q.empty()){
        count++;
        int steps = q.size();
        for(int i = 0; i < steps; i++)
        {
            pair<int,int> pos = q.front(); q.pop();
            if(pos.first != 0)
            {
                if(!tomatos[pos.first-1][pos.second]) {
                    tomatos[pos.first-1][pos.second] = true;
                    q.push(make_pair(pos.first-1,pos.second));
                }
            }
            if(pos.first != n-1)
            {
                if(!tomatos[pos.first+1][pos.second]) 
                {
                    q.push(make_pair(pos.first+1,pos.second));
                    tomatos[pos.first+1][pos.second] = true;
                }
            }
            if(pos.second != 0)
            {
                if(!tomatos[pos.first][pos.second-1]) {
                    q.push(make_pair(pos.first,pos.second-1));
                    tomatos[pos.first][pos.second-1] = true;
                }
            }
            if(pos.second != m-1)
            {
                if(!tomatos[pos.first][pos.second+1]) 
                {
                    q.push(make_pair(pos.first,pos.second+1));
                    tomatos[pos.first][pos.second+1] = true;
                }
            }
        }
    }
    
    bool all_check = true;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!tomatos[i][j]) {all_check = false; break;}
        } 
        if(!all_check)  break;
    }
    if(all_check) cout << count;
    else cout << -1;
}