#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define MI_INF -2000000000


using namespace std;

int plus_arrs[200000];
int minus_arrs[200000];
int num_arrs[200000];

int main() {
    fastio;
    fill(plus_arrs, plus_arrs+200000, MI_INF);
    fill(minus_arrs, minus_arrs+200000, MI_INF);
    fill(num_arrs, num_arrs+200000, MI_INF);
    string s; cin >> s;
    if(s[0] == '-') num_arrs[0] = 1;
    else if(s[0] == '+') num_arrs[0] = 10;

    if(s.length() > 1)
    {
        if(s[0] == '+' && s[1] == '-')
            num_arrs[1] = 11;
    }

    for(int i = 1; i < s.length(); i++)
    {
        int num_max = MI_INF, minus_max = MI_INF, plus_max = MI_INF;
        if(s[i] == '-')
        {   
            if(s[i-1] == '+' && i != 1)
            {
                if(plus_arrs[i-2] != MI_INF) num_max = max(plus_arrs[i-2]+11,num_max);
                if(minus_arrs[i-2] != MI_INF) num_max = max(minus_arrs[i-2]-11,num_max);
            }

            if(num_arrs[i-1] != MI_INF) minus_max = max(num_arrs[i-1], minus_max);

            if(plus_arrs[i-1] != MI_INF) num_max = max(plus_arrs[i-1] + 1, num_max);
            if(minus_arrs[i-1] != MI_INF) num_max = max(minus_arrs[i-1]-1,num_max);
        }
        else if(s[i] == '+')
        {
            if(num_arrs[i-1] != MI_INF) plus_max = max(num_arrs[i-1], plus_max);
            if(plus_arrs[i-1] != MI_INF) num_max = max(plus_arrs[i-1] + 10, num_max);
            if(minus_arrs[i-1] != MI_INF) num_max = max(minus_arrs[i-1]-10,num_max);
        }
        plus_arrs[i] = plus_max;
        minus_arrs[i] = minus_max;
        num_arrs[i] = max(num_arrs[i],num_max);
    }

    cout << num_arrs[s.length()-1];
}