#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> acid_arrs;
vector<int> al_arrs;

int main() {
    fastio;
    int n, temp, acid_res, al_res; cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp >= 0) acid_arrs.push_back(temp);
        else al_arrs.push_back(-temp);
    }
    
    sort(acid_arrs.begin(), acid_arrs.end());
    sort(al_arrs.begin(), al_arrs.end());

    if(acid_arrs.empty()) cout << -al_arrs[1] << ' ' << -al_arrs[0];
    else if(al_arrs.empty()) cout << acid_arrs[0] << ' ' << acid_arrs[1];
    else{
        int mind = 1000000001;

        for(int i = 0; i < acid_arrs.size(); i++)
        {
            int pos = upper_bound(al_arrs.begin(), al_arrs.end(), acid_arrs[i]) - al_arrs.begin();
            if(pos != al_arrs.size())
            {
                if(mind > abs(acid_arrs[i]-al_arrs[pos]))
                {
                    acid_res = acid_arrs[i]; al_res = al_arrs[pos];
                    mind = abs(acid_arrs[i]-al_arrs[pos]);
                }
            }
            if(pos != 0)
            {
                if(mind > abs(acid_arrs[i]-al_arrs[pos-1]))
                {
                    acid_res = acid_arrs[i]; al_res = al_arrs[pos-1];
                    mind = abs(acid_arrs[i]-al_arrs[pos-1]);
                }
            }
        }
        if((mind > al_arrs[0] + al_arrs[1] && al_arrs.size() >= 2) || (mind > acid_arrs[0] + acid_arrs[1] && acid_arrs.size() >= 2))
        {
            if(al_arrs[0] + al_arrs[1] < acid_arrs[0] + acid_arrs[1]) cout << -al_arrs[1] << ' ' << -al_arrs[0];
            else cout << acid_arrs[0] << ' ' << acid_arrs[1];
        }
        else{
            cout << -al_res << ' ' << acid_res;
        }
    }
    

    return 0;
}