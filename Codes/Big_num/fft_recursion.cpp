//from https://tistory.joonhyung.xyz/6

#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
using namespace std;

typedef complex<double> comp;


using namespace std;

void fft(vector<comp> &a, vector<comp> &A)
{
    int n = (int) a.size();
    if(n == 1) 
    {
        A[0] = a[0];
        return;
    }

    vector<comp> even(n/2), odd(n/2), Even(n/2), Odd(n/2);

    for(int i = 0; i < n/2; i++)
    {
        even[i] = a[2 * i];
        odd[i] = a[2 * i + 1];
    }
    fft(even, Even);
    fft(odd, Odd);

    double ind = -2.0 * M_PI / n;

    comp odd_cof_r = comp(cos(ind), sin(ind));
    comp odd_cof = comp(1);

    for(int i = 0; i < n/2; i++)
    {
        A[i] = Even[i] + odd_cof * Odd[i];
        A[i + n/2] = Even[i] - odd_cof * Odd[i];
        odd_cof *= odd_cof_r;
    }
}

void ifft(vector<comp> &A, vector<comp> &a)
{
    reverse(++A.begin(), A.end());
    fft(A,a);
    int n = (int) a.size();
    for(int i = 0; i < n; i++)
        a[i] /= n;
}

vector<int> multiply(vector<int> a, vector<int> b)
{
    int n = 1;
    vector<int> c(a.size() + b.size() -1);
    while(a.size() >= n || b.size() >= n) n *= 2;
    n*=2;
    a.resize(n); b.resize(n);

    vector<comp> a_c(n), b_c(n), A_c(n), B_c(n), c_c(n), C_c(n);
    for(int i = 0; i < n; i++)
    {
        a_c[i] = comp(a[i], 0);
        b_c[i] = comp(b[i], 0);
    }
    

    fft(a_c, A_c); fft(b_c, B_c);

    for(int i = 0; i < n; i++)
    {
        C_c[i] = A_c[i] * B_c[i];
    }
    ifft(C_c, c_c);
    for(int i = 0; i < c.size(); i++)
    {
        c[i] = round(c_c[i].real());
    }

    for(int i = c.size()-1; i > 0; i--)
    {
        if(c[i] >= 10) {
            c[i-1] += c[i]/10; c[i] = c[i]%10;
        }
    }
    return c;

}

vector<int> v,u;

int main() {
    fastio;
    string a, b;
    cin >> a >> b;
    if(a == "0" || b == "0") 
    {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < a.size(); i++)
    {
        v.push_back(a[i]-'0');
    }

    for(int i = 0; i < b.size(); i++)
    {
        u.push_back(b[i]-'0');
    }

    vector<int> w = multiply(v, u);
    for(int i=0; i<w.size(); i++) cout << w[i];
}