#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

vector<tuple<int,int,int>> rooms;

long long n, h_atk;

long long bsearch(long long start, long long end)
{
    long long st = start, ed = end;
    long long mid,result;
    long long cou;
    while(st <= ed){
        cou = 0;
        mid = (st + ed)/2;
        bool possible = true;
        long long h_cur_hp = mid;
        long long h_cur_atk = h_atk;
        for(int i = 0; i < n; i++)
        {
            int cur_t = get<0>(rooms[i]), cur_a = get<1>(rooms[i]), cur_h = get<2>(rooms[i]);
            if(cur_t == 1)
            {
                long long attacked_ct = (cur_h - 1)/h_cur_atk;
                h_cur_hp -= attacked_ct * cur_a;
                if(h_cur_hp <= 0) {
                    possible = false; break;
                }
            }
            else if(cur_t == 2)
            {
                h_cur_atk += cur_a;
                h_cur_hp = min(mid, h_cur_hp + cur_h);
            }
        }
        if(possible){
            ed = mid-1;
            result = mid;
        }
        else
        {
            st = mid + 1;
        }
        //cout << mid << ' ' << possible << endl;
    }
    return result;
}



int main() {
    fastio;
    cin >> n >> h_atk;
    int ti, ai, hi;
    for(int i = 0; i < n; i++)
    {
        cin >> ti >> ai >> hi;
        rooms.push_back({ti,ai,hi});
    }
    cout << bsearch(1, 9000000000000000000);
}