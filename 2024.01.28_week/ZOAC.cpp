#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<string> print_target;

bool arrs[100]{};


int main() {
    fastio;
    int t;
    string s; cin >> s; 
    print_target.push_back(s);
    int rep = s.length();
    for(int i = 0; i < rep-1; i++)
    {
        string min_target = s;
        min_target.erase(min_target.begin());
        for(int j = 1; j < s.length(); j++)
        {
            string temp = s;
            temp.erase(temp.begin() + j);
            if(temp < min_target) min_target = temp;
        }
        print_target.push_back(min_target);
        s = min_target;
    }

    for(int i = print_target.size()-1; i >=0; i--)
        cout << print_target[i] << "\n";


}