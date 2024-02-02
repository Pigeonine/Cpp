#include <iostream>
#include <vector>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> lan_len;

int lan_search(int start, int end, int target)
{
    long long st = start, ed = end;
    long long mid,result;
    long long cou;
    while(st <= ed){
        cou = 0;
        mid = (st + ed)/2;
        for(int i = 0; i < lan_len.size(); i++)
        {
            cou += lan_len[i]/mid;
        }
        if(cou >= target){
            st = mid+1;
            result = mid;
        }
        else if(cou < target)
        {
            ed = mid - 1;
        }
    }
    return result;
}


int main() {
    fastio;
    int k, n, length;
    cin >> k >> n;
    int maxl = 0;
    for(int i = 0; i < k; i++) 
    {
        cin >> length; lan_len.push_back(length);
        maxl = max(maxl, length);
    }
    cout << lan_search(1, maxl, n);
    
}