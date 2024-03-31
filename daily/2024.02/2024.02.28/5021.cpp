#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

map<string,int> mp;

map<int,string> mps;


vector<int> arrs[151];

int pts[151];
double blood[151];
queue<int> pq;

int main() {
    fastio;
    int n, m; cin >> n >> m;
    string s, fa, ma;
    cin >> s; mp.insert({s,1}); mps.insert({1,s});
    blood[1] = 1;
    int numb = 2;
    for (int i = 0; i < n; i++)
    {   
        cin >> s >> fa >> ma;
        if(mp.find(s) == mp.end())
        {
            mp.insert({s,numb}); mps.insert({numb,s});
            numb++;
        }

        if(mp.find(fa) == mp.end())
        {
            mp.insert({fa,numb}); mps.insert({numb,fa});
            numb++;
        }

        if(mp.find(ma) == mp.end())
        {
            mp.insert({ma,numb}); mps.insert({numb,ma});
            numb++;
        }

        pts[mp[s]] += 2;
        arrs[mp[fa]].push_back(mp[s]);arrs[mp[ma]].push_back(mp[s]);
    }
    for(int i = 1; i < numb; i++)
        if(pts[i] == 0) pq.push(i);
    
    while(!pq.empty())
    {
        int temp = pq.front(); pq.pop();
        for(int i = 0; i < arrs[temp].size(); i++)
        {
            blood[arrs[temp][i]] += blood[temp] / 2.0; pts[arrs[temp][i]]--;
            if(pts[arrs[temp][i]] == 0) pq.push(arrs[temp][i]);
        }
    }
    string her; double her_blood = 0.0;
    for(int i = 0; i < m; i++)
    {
        string temp; cin >> temp;
        if(blood[mp[temp]] >= her_blood)
        {
            her = temp; her_blood = blood[mp[temp]];
        }
    }

    cout << her;

}