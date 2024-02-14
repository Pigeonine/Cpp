#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    string a, b;
    while(true)
    {
        int p1_score = 0, p2_score = 0;
        cin >> a >> b;
        if(a == "E" && b == "E") break;

        for(int i = 0; i < a.length(); i++)
        {
            switch (a[i])
            {
            case 'R':
                if(b[i] == 'S') p1_score++;
                else if(b[i] == 'P') p2_score++;
                break;
            case 'P':
                if(b[i] == 'R') p1_score++;
                else if(b[i] == 'S') p2_score++;
                break;
            case 'S':
                if(b[i] == 'P') p1_score++;
                else if(b[i] == 'R') p2_score++;
                break;    
            default:
                break;
            }
            
        }
        cout << "P1: " << p1_score << "\n" << "P2: " << p2_score << "\n";
    }
}