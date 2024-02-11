#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;
int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int w_days[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int main() {
    fastio;
    int y, m, d, yd, md, dd;
    cin >> y >> m >> d >> yd >> md >> dd;
    if(yd - y > 1000 || (yd - y == 1000 &&(md > m || (md == m && dd >= d))))
        cout << "gg";
    else
    {  
        int counts = 0;
        for(int i = y+1; i < yd; i++)
        {
            if(i % 400 == 0 ||(i % 4 == 0 && i % 100 != 0)) counts += 366;
            else counts += 365;
        }
        
        if(y == yd)
        {
            if(y % 400 == 0 ||(y % 4 == 0 && y % 100 != 0))
            {
                for(int i = m-1; i < md-1; i++) counts += w_days[i];
                counts += dd;
                counts -= d;
            }
            else{
                for(int i = m-1; i < md-1; i++) counts += days[i];
                counts += dd;
                counts -= d;
            }
        }
        else{
            if(y % 400 == 0 ||(y % 4 == 0 && y % 100 != 0))
            {
                counts += 366;
                for(int i = 0; i < m-1; i++) counts -= w_days[i];
                counts -= d;
            
            }
            else{
                counts += 365;
                for(int i = 0; i < m-1; i++) counts -= days[i];
                counts -= d;
            }

            if(yd % 400 == 0 ||(yd % 4 == 0 && yd % 100 != 0))
            {
                for(int i = 0; i < md-1; i++) counts += w_days[i];
                counts += dd;
            }
            else{
                for(int i = 0; i < md-1; i++) counts += days[i];
                counts += dd;
            }   
        }
        cout << "D-" << counts;
    }
}   