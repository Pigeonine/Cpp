#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> customers;

int times[1000001];

int main() {
    fastio;
    int n, m, temp; cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> temp; customers.push_back(temp);
        
    }
    sort(customers.begin(), customers.end());
    int st = 0; 
    
    for(int i = 0; i < n; i++)
    {
        
        if(times[customers[i]]){cout << "fail"; return 0;}
        else times[customers[i]] = true;
        
        for(int j = m; j >= 1; j--)
        {
            if(customers[i]-j < 0) {
                if(j == 1){cout << "fail"; return 0;}
                continue;
            }
            if(!times[customers[i]-j]) 
            {
                times[customers[i]-j] = true; break;
            }
            

            if(j == 1){cout << "fail"; return 0;}
         }

        while(true)
        {
            if(times[st]) st++;
            else {times[st] = true; st++; break;}

            if(st >= customers[i]){cout << "fail"; return 0;}
        }
    }

    

    cout << "success";
}