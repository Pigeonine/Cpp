#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
using namespace std;

int modular(const string& s, int d)
{
	long long res = 0; int modul = 1;
	for (int i = s.length()-1; i >= 0; i--)
	{
		res = (res + ((long long) (s[i] - '0') * modul) % d) % d;
		modul = (modul * 10) % d;
	}
	return res;
}
bool pr[1000001]{};

void init(){
    pr[1] = true;
    int i = 2;
    while(i <= 1000000)
    {
        if(!pr[i]) 
        {
            for(int j = 2*i; j <= 1000000; j += i) pr[j] = true;
        }
        i++;
    }
}

int main() {
	fastio;
	string p; int k;
	cin >> p >> k;
    init();
	for (int i = 2; i < k; i++)
	{
		if(!pr[i])
        {
            if (modular(p, i) == 0) { 
			    cout << "BAD " << i;
			    return 0;
		    }
        }
        
	}
	cout << "GOOD";
}