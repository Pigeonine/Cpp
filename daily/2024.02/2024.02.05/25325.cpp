#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<string> names;
int arrs[101]{};
vector<pair<int, string>> sorts;

bool calc(pair<int, string> a, pair<int, string> b) {
    if(a.first > b.first) return true;
    else if(a.first < b.first) return false;
    else if(a.first == b.first)
        return a.second < b.second;
}

int main() {
    fastio;
    int n; cin >> n;
    string s;
    for(int i = 0; i < n; i++)
    {
        cin >> s; names.push_back(s);
    }
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        getline(cin, s);
        stringstream ss(s);
        string word;
        while(getline(ss,word,' '))
            arrs[find(names.begin(),names.end(),word) - names.begin()]++;
    }   
    for(int i = 0; i < n; i++)
        sorts.push_back(make_pair(arrs[i], names[i]));
    sort(sorts.begin(), sorts.end(), calc);
    for(int i = 0; i < n; i++)
        cout << sorts[i].second << ' ' << sorts[i].first << "\n";
}
