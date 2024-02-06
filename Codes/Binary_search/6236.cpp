#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<int> arrs;

int search(int start, int end, int target)
{
    long long st = start, ed = end;
    long long mid,result;
    long long cou;
    while(st <= ed){
        mid = (st + ed)/2;
        int pt_number = 1, pt_money = mid;
        for(int i = 0; i < arrs.size(); i++)
        {
            if(pt_money < arrs[i])
            {
                pt_number++; pt_money = mid - arrs[i];
            }
            else pt_money -=arrs[i];
        }
        if(pt_number <= target){
            ed = mid-1;
            result = mid;
        }
        else if(pt_number > target)
        {
            st = mid + 1;
        }
    }
    return result;
}


int main() {
    fastio;
    int n, m, money, max_money = 0, total_money = 0; cin >> n >> m;
    for(int i = 0; i < n; i++)
    {

        cin >> money; arrs.push_back(money); max_money = max(money, max_money); total_money += money;
    }

    cout << search(max_money, total_money, m);
}