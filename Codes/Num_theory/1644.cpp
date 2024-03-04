#include <iostream>
#include <vector>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

bool pr[4000001];

vector<int> primes;

void init(int n)
{
    pr[1] = true;
    for(int i = 2; i <= n;i++)
    {
        if(!pr[i])
        {
            primes.push_back(i);
            for(int j = 2 * i; j <= n; j += i) pr[j] = true;
        }
    }
}

int main(){
    int n; cin >> n;
    init(n);
    if(primes.empty())
    {
        cout << 0; return 0;
    }
    int sums = primes[0]; 
    int fr = 0, bk = 1, counts = 0;
    int pr_size = primes.size();
    //for(auto i : primes) cout << i << endl;
    while(true)
    {
        //cout << fr << ' ' << bk << ' ' << sums << "\n";
        if(sums < n)
        {
            if(bk >= pr_size) break;
            sums += primes[bk++];
        }
        else if(sums > n)
        {
            sums -= primes[fr++];
        }
        else if(sums == n)
        {
            counts++;
            if(bk >= pr_size) break;
            sums += primes[bk++];
            sums -= primes[fr++];
        }
    }
    cout << counts;
}