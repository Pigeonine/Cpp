#include <iostream>
#include <algorithm>
#include <cmath>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

long long gcd(long long a, long long b)
{
    while(a % b != 0)
    {
        long long r = a % b;
        a = b; b = r;
    }
    return b;
}

int main(){
    fastio;
    int n; cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        long long ind = s.find('(');
        
        if(ind == -1)
        {
            string s_sub = s.substr(2);
            long long nom = pow(10,s_sub.length());
            long long denom = stoi(s_sub); 
            long long dngcd = gcd(nom,denom);
            cout << denom/dngcd << '/' << nom/dngcd << "\n";
        }
        else
        {
            long long l_len = 0;
            long long nom = 1;
            string d_num = "0";
            if(ind != 2)
            {
                d_num = s.substr(2, ind - 2);
                l_len = d_num.length();
                //cout << s_sub << endl;
                nom = pow(10,d_num.length());
            }

            string s_sub = d_num;
            s_sub.append(s.substr(ind+1,s.find(')')-ind-1));
            long long i_len = s.substr(ind+1,s.find(')')-ind-1).length();
            string nines;
            for(int i = 0; i < i_len; i++) nines.push_back('9');
            long long nines_ll = stoll(nines) * nom;
            long long d_num_ll = stoll(s_sub) - stoll(d_num);
            long long gcd_n = gcd(nines_ll, d_num_ll);
            cout << d_num_ll/gcd_n << '/' << nines_ll/gcd_n << "\n";
            
        }
    }
}