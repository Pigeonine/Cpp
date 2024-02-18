#include <iostream>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;
int n;
int main(){
    fastio;
    cin >> n;
    for(int i = 2; i * i <= n; i++)
    {
        while(n % i == 0)
        {
            cout << i << "\n";
            n /= i;
        }
    }
    if(n > 1) cout << n;
}
